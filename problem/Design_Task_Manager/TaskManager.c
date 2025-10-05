typedef struct
{
    int key;
    int value;
    int state;
} MapEntry;

typedef struct
{
    MapEntry *tab;
    int cap;
    int cnt;
} IntMap;

typedef struct
{
    int *pri;
    int *id;
    int size;
    int cap;
} MaxHeap;

typedef struct
{
    MaxHeap heap;
    IntMap priMap;
    IntMap ownerMap;
} TaskManager;

static unsigned int hash_int(int x)
{
    unsigned int u = (unsigned int)x;
    u ^= u >> 16;
    u *= 0x7feb352dU;
    u ^= u >> 15;
    u *= 0x846ca68bU;
    u ^= u >> 16;
    return u;
}

static void mapInit(IntMap *m)
{
    m->cap = 16;
    m->cnt = 0;
    m->tab = (MapEntry *)calloc(m->cap, sizeof(MapEntry));
}

static void mapFree(IntMap *m)
{
    free(m->tab);
    m->tab = NULL;
    m->cap = m->cnt = 0;
}

static void mapRehash(IntMap *m)
{
    int oldcap = m->cap;
    MapEntry *old = m->tab;
    m->cap <<= 1;
    m->tab = (MapEntry *)calloc(m->cap, sizeof(MapEntry));
    m->cnt = 0;
    for (int i = 0; i < oldcap; i++)
    {
        if (old[i].state == 1)
        {
            int key = old[i].key, val = old[i].value;
            unsigned int h = hash_int(key);
            int cap = m->cap;
            int idx = (int)(h % (unsigned int)cap);
            int first_del = -1;
            for (;;)
            {
                MapEntry *e = &m->tab[idx];
                if (e->state == 0)
                {
                    int ins = (first_del >= 0 ? first_del : idx);
                    m->tab[ins].key = key;
                    m->tab[ins].value = val;
                    m->tab[ins].state = 1;
                    m->cnt++;
                    break;
                }
                else if (e->state == 2)
                {
                    if (first_del < 0)
                        first_del = idx;
                }
                else if (e->key == key)
                {
                    e->value = val;
                    break;
                }
                idx++;
                if (idx == cap)
                    idx = 0;
            }
        }
    }
    free(old);
}

static void mapSet(IntMap *m, int key, int value)
{
    if ((m->cnt + 1) * 10 >= m->cap * 7)
        mapRehash(m);
    unsigned int h = hash_int(key);
    int cap = m->cap;
    int idx = (int)(h % (unsigned int)cap);
    int first_del = -1;
    for (;;)
    {
        MapEntry *e = &m->tab[idx];
        if (e->state == 0)
        {
            int ins = (first_del >= 0 ? first_del : idx);
            m->tab[ins].key = key;
            m->tab[ins].value = value;
            if (m->tab[ins].state != 1)
            {
                m->tab[ins].state = 1;
                m->cnt++;
            }
            return;
        }
        else if (e->state == 2)
        {
            if (first_del < 0)
                first_del = idx;
        }
        else if (e->key == key)
        {
            e->value = value;
            return;
        }
        idx++;
        if (idx == cap)
            idx = 0;
    }
}

static int mapGet(IntMap *m, int key, int *out)
{
    unsigned int h = hash_int(key);
    int cap = m->cap;
    int idx = (int)(h % (unsigned int)cap);
    for (;;)
    {
        MapEntry *e = &m->tab[idx];
        if (e->state == 0)
            return 0;
        if (e->state == 1 && e->key == key)
        {
            *out = e->value;
            return 1;
        }
        idx++;
        if (idx == cap)
            idx = 0;
    }
}

static void heapInit(MaxHeap *hp)
{
    hp->cap = 16;
    hp->size = 0;
    hp->pri = (int *)malloc(hp->cap * sizeof(int));
    hp->id = (int *)malloc(hp->cap * sizeof(int));
}

static void heapFree(MaxHeap *hp)
{
    free(hp->pri);
    free(hp->id);
    hp->pri = hp->id = NULL;
    hp->cap = hp->size = 0;
}

static int heapCmp(MaxHeap *hp, int i, int j)
{
    if (hp->pri[i] != hp->pri[j])
        return hp->pri[i] > hp->pri[j];
    return hp->id[i] > hp->id[j];
}

static void heapSwap(MaxHeap *hp, int i, int j)
{
    int tp = hp->pri[i];
    hp->pri[i] = hp->pri[j];
    hp->pri[j] = tp;
    int ti = hp->id[i];
    hp->id[i] = hp->id[j];
    hp->id[j] = ti;
}

static void heapUp(MaxHeap *hp, int i)
{
    while (i > 0)
    {
        int p = (i - 1) >> 1;
        if (heapCmp(hp, p, i))
            break;
        heapSwap(hp, p, i);
        i = p;
    }
}

static void heapDown(MaxHeap *hp, int i)
{
    int n = hp->size;
    for (;;)
    {
        int l = (i << 1) + 1, r = l + 1, m = i;
        if (l < n && heapCmp(hp, l, m))
            m = l;
        if (r < n && heapCmp(hp, r, m))
            m = r;
        if (m == i)
            break;
        heapSwap(hp, i, m);
        i = m;
    }
}

static void heapEnsure(MaxHeap *hp)
{
    if (hp->size < hp->cap)
        return;
    hp->cap <<= 1;
    hp->pri = (int *)realloc(hp->pri, hp->cap * sizeof(int));
    hp->id = (int *)realloc(hp->id, hp->cap * sizeof(int));
}

static void heapPush(MaxHeap *hp, int pri, int id)
{
    heapEnsure(hp);
    int i = hp->size++;
    hp->pri[i] = pri;
    hp->id[i] = id;
    heapUp(hp, i);
}

static int heapEmpty(MaxHeap *hp) { return hp->size == 0; }

static void heapPop(MaxHeap *hp, int *pri, int *id)
{
    *pri = hp->pri[0];
    *id = hp->id[0];
    int last = --hp->size;
    if (last >= 0)
    {
        if (last >= 0)
        {
            hp->pri[0] = hp->pri[last];
            hp->id[0] = hp->id[last];
        }
        if (hp->size > 0)
            heapDown(hp, 0);
    }
}

TaskManager *taskManagerCreate(int **tasks, int tasksSize, int *tasksColSize)
{
    TaskManager *obj = (TaskManager *)malloc(sizeof(TaskManager));
    heapInit(&obj->heap);
    mapInit(&obj->priMap);
    mapInit(&obj->ownerMap);
    for (int i = 0; i < tasksSize; i++)
    {
        int userId = tasks[i][0], taskId = tasks[i][1], priority = tasks[i][2];
        heapPush(&obj->heap, priority, taskId);
        mapSet(&obj->priMap, taskId, priority);
        mapSet(&obj->ownerMap, taskId, userId);
    }
    return obj;
}

void taskManagerAdd(TaskManager *obj, int userId, int taskId, int priority)
{
    heapPush(&obj->heap, priority, taskId);
    mapSet(&obj->priMap, taskId, priority);
    mapSet(&obj->ownerMap, taskId, userId);
}

void taskManagerEdit(TaskManager *obj, int taskId, int newPriority)
{
    heapPush(&obj->heap, newPriority, taskId);
    mapSet(&obj->priMap, taskId, newPriority);
}

void taskManagerRmv(TaskManager *obj, int taskId)
{
    mapSet(&obj->priMap, taskId, -1);
}

int taskManagerExecTop(TaskManager *obj)
{
    int p, id;
    while (!heapEmpty(&obj->heap))
    {
        heapPop(&obj->heap, &p, &id);
        int cur = -2;
        if (!mapGet(&obj->priMap, id, &cur))
            cur = -1;
        if (cur == p)
        {
            mapSet(&obj->priMap, id, -1);
            int owner = -1;
            if (!mapGet(&obj->ownerMap, id, &owner))
                owner = -1;
            return owner;
        }
    }
    return -1;
}

void taskManagerFree(TaskManager *obj)
{
    if (!obj)
        return;
    heapFree(&obj->heap);
    mapFree(&obj->priMap);
    mapFree(&obj->ownerMap);
    free(obj);
}
