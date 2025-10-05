#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    int price, shop, movie;
} Node;

typedef struct
{
    Node *a;
    int sz, cap;
} Heap;

static int node_cmp(Node x, Node y)
{
    if (x.price != y.price)
        return x.price < y.price ? -1 : 1;
    if (x.shop != y.shop)
        return x.shop < y.shop ? -1 : 1;
    if (x.movie != y.movie)
        return x.movie < y.movie ? -1 : 1;
    return 0;
}

static void heap_swap(Node *a, Node *b)
{
    Node t = *a;
    *a = *b;
    *b = t;
}

static void heap_init(Heap *h)
{
    h->a = NULL;
    h->sz = 0;
    h->cap = 0;
}

static void heap_reserve(Heap *h, int need)
{
    if (h->cap >= need)
        return;
    int ncap = h->cap ? h->cap : 4;
    while (ncap < need)
        ncap <<= 1;
    h->a = (Node *)realloc(h->a, ncap * sizeof(Node));
    h->cap = ncap;
}

static void heap_push(Heap *h, Node v)
{
    heap_reserve(h, h->sz + 1);
    int i = h->sz++;
    h->a[i] = v;
    while (i > 0)
    {
        int p = (i - 1) >> 1;
        if (node_cmp(h->a[p], h->a[i]) <= 0)
            break;
        heap_swap(&h->a[p], &h->a[i]);
        i = p;
    }
}

static int heap_empty(Heap *h) { return h->sz == 0; }

static Node heap_top(Heap *h) { return h->a[0]; }

static void heap_pop(Heap *h)
{
    int n = --h->sz;
    if (n <= 0)
        return;
    h->a[0] = h->a[n];
    int i = 0;
    for (;;)
    {
        int l = i * 2 + 1, r = l + 1, m = i;
        if (l < h->sz && node_cmp(h->a[l], h->a[m]) < 0)
            m = l;
        if (r < h->sz && node_cmp(h->a[r], h->a[m]) < 0)
            m = r;
        if (m == i)
            break;
        heap_swap(&h->a[i], &h->a[m]);
        i = m;
    }
}

typedef struct
{
    uint64_t key;
    int price;
    unsigned char state;
    unsigned char used;
} HEntry;

typedef struct
{
    HEntry *tab;
    int cap;
    int cnt;
} HMap;

static uint64_t mix64(uint64_t x)
{
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    x *= 0xc4ceb9fe1a85ec53ULL;
    x ^= x >> 33;
    return x;
}

static void hmap_init(HMap *m, int need)
{
    int cap = 1;
    while (cap < (need << 2))
        cap <<= 1;
    m->tab = (HEntry *)calloc(cap, sizeof(HEntry));
    m->cap = cap;
    m->cnt = 0;
}

static HEntry *hmap_get_slot(HMap *m, uint64_t key)
{
    uint64_t h = mix64(key);
    int mask = m->cap - 1;
    int i = (int)(h & mask);
    for (;;)
    {
        if (!m->tab[i].used || m->tab[i].key == key)
            return &m->tab[i];
        i = (i + 1) & mask;
    }
}

static HEntry *hmap_put(HMap *m, uint64_t key, int price, unsigned char state)
{
    HEntry *e = hmap_get_slot(m, key);
    if (!e->used)
    {
        e->used = 1;
        e->key = key;
        m->cnt++;
    }
    e->price = price;
    e->state = state;
    return e;
}

static HEntry *hmap_find(HMap *m, uint64_t key)
{
    uint64_t h = mix64(key);
    int mask = m->cap - 1;
    int i = (int)(h & mask);
    for (;;)
    {
        if (!m->tab[i].used)
            return NULL;
        if (m->tab[i].key == key)
            return &m->tab[i];
        i = (i + 1) & mask;
    }
}

typedef struct MovieRentingSystem
{
    int nshops;
    int maxMovie;
    Heap *avail;
    Heap rented;
    HMap map;
} MovieRentingSystem;

static inline uint64_t mkkey(int shop, int movie) { return (((uint64_t)(uint32_t)shop) << 32) ^ (uint32_t)movie; }

MovieRentingSystem *movieRentingSystemCreate(int n, int **entries, int entriesSize, int *entriesColSize)
{
    int maxMovie = 0;
    for (int i = 0; i < entriesSize; i++)
        if (entries[i][1] > maxMovie)
            maxMovie = entries[i][1];
    MovieRentingSystem *obj = (MovieRentingSystem *)calloc(1, sizeof(MovieRentingSystem));
    obj->nshops = n;
    obj->maxMovie = maxMovie;
    obj->avail = (Heap *)malloc((maxMovie + 1) * sizeof(Heap));
    for (int i = 0; i <= maxMovie; i++)
        heap_init(&obj->avail[i]);
    heap_init(&obj->rented);
    hmap_init(&obj->map, entriesSize + 16);
    for (int i = 0; i < entriesSize; i++)
    {
        int shop = entries[i][0], movie = entries[i][1], price = entries[i][2];
        hmap_put(&obj->map, mkkey(shop, movie), price, 0);
        heap_push(&obj->avail[movie], (Node){price, shop, movie});
    }
    return obj;
}

int *movieRentingSystemSearch(MovieRentingSystem *obj, int movie, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 5);
    int cnt = 0;
    if (movie < 0 || movie > obj->maxMovie)
    {
        *returnSize = 0;
        return res;
    }
    Heap *h = &obj->avail[movie];
    Node *popped = NULL;
    int cap = 0;
    int pc = 0;
    int seen[5];
    int seen_sz = 0;
    while (cnt < 5 && !heap_empty(h))
    {
        Node top = heap_top(h);
        heap_pop(h);
        HEntry *e = hmap_find(&obj->map, mkkey(top.shop, top.movie));
        if (!e || e->state != 0)
            continue;
        if (pc == cap)
        {
            cap = cap ? cap << 1 : 8;
            popped = (Node *)realloc(popped, cap * sizeof(Node));
        }
        popped[pc++] = top;
        int ok = 1;
        for (int i = 0; i < seen_sz; i++)
        {
            if (seen[i] == top.shop)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            res[cnt++] = top.shop;
            if (seen_sz < 5)
                seen[seen_sz++] = top.shop;
        }
    }
    int uniq_cnt = 0;
    int uniq_shop[64];
    for (int i = 0; i < pc; i++)
    {
        int ok = 1;
        for (int j = 0; j < uniq_cnt; j++)
        {
            if (uniq_shop[j] == popped[i].shop)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            heap_push(h, popped[i]);
            if (uniq_cnt < 64)
                uniq_shop[uniq_cnt++] = popped[i].shop;
        }
    }
    free(popped);
    *returnSize = cnt;
    return res;
}

void movieRentingSystemRent(MovieRentingSystem *obj, int shop, int movie)
{
    HEntry *e = hmap_find(&obj->map, mkkey(shop, movie));
    if (!e)
        return;
    e->state = 1;
    heap_push(&obj->rented, (Node){e->price, shop, movie});
}

void movieRentingSystemDrop(MovieRentingSystem *obj, int shop, int movie)
{
    HEntry *e = hmap_find(&obj->map, mkkey(shop, movie));
    if (!e)
        return;
    e->state = 0;
    heap_push(&obj->avail[movie], (Node){e->price, shop, movie});
}

int **movieRentingSystemReport(MovieRentingSystem *obj, int *returnSize, int **returnColumnSizes)
{
    int **out = (int **)malloc(sizeof(int *) * 5);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 5);
    int cnt = 0;
    Node *popped = NULL;
    int cap = 0;
    int pc = 0;
    int seen_cnt = 0;
    int seen_shop[5];
    int seen_movie[5];
    while (cnt < 5 && !heap_empty(&obj->rented))
    {
        Node top = heap_top(&obj->rented);
        heap_pop(&obj->rented);
        HEntry *e = hmap_find(&obj->map, mkkey(top.shop, top.movie));
        if (!e || e->state != 1)
            continue;
        int dup = 0;
        for (int i = 0; i < seen_cnt; i++)
        {
            if (seen_shop[i] == top.shop && seen_movie[i] == top.movie)
            {
                dup = 1;
                break;
            }
        }
        if (pc == cap)
        {
            cap = cap ? cap << 1 : 8;
            popped = (Node *)realloc(popped, cap * sizeof(Node));
        }
        popped[pc++] = top;
        if (!dup)
        {
            out[cnt] = (int *)malloc(sizeof(int) * 2);
            out[cnt][0] = top.shop;
            out[cnt][1] = top.movie;
            (*returnColumnSizes)[cnt] = 2;
            cnt++;
            if (seen_cnt < 5)
            {
                seen_shop[seen_cnt] = top.shop;
                seen_movie[seen_cnt] = top.movie;
                seen_cnt++;
            }
        }
    }
    int rein_cnt = 0;
    int rein_shop[64];
    int rein_movie[64];
    for (int i = 0; i < pc; i++)
    {
        int dup = 0;
        for (int j = 0; j < rein_cnt; j++)
        {
            if (rein_shop[j] == popped[i].shop && rein_movie[j] == popped[i].movie)
            {
                dup = 1;
                break;
            }
        }
        if (!dup)
        {
            heap_push(&obj->rented, popped[i]);
            if (rein_cnt < 64)
            {
                rein_shop[rein_cnt] = popped[i].shop;
                rein_movie[rein_cnt] = popped[i].movie;
                rein_cnt++;
            }
        }
    }
    free(popped);
    *returnSize = cnt;
    return out;
}

void movieRentingSystemFree(MovieRentingSystem *obj)
{
    if (!obj)
        return;
    for (int i = 0; i <= obj->maxMovie; i++)
        free(obj->avail[i].a);
    free(obj->avail);
    free(obj->rented.a);
    free(obj->map.tab);
    free(obj);
}
