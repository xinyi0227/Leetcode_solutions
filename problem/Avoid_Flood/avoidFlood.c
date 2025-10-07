#include <stdlib.h>

typedef struct
{
    int *parent;
    int n;
} DSU;

static DSU *dsu_create(int n)
{
    DSU *d = (DSU *)malloc(sizeof(DSU));
    d->n = n + 1;
    d->parent = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
        d->parent[i] = i;
    return d;
}

static int dsu_find(DSU *d, int x)
{
    if (x > d->n - 1)
        return d->n - 1;
    int r = x;
    while (d->parent[r] != r)
        r = d->parent[r];
    while (x != r)
    {
        int nx = d->parent[x];
        d->parent[x] = r;
        x = nx;
    }
    return r;
}

static void dsu_unite_next(DSU *d, int i)
{
    int r = dsu_find(d, i + 1);
    if (i <= d->n - 1)
        d->parent[i] = r;
}

static void dsu_free(DSU *d)
{
    if (!d)
        return;
    free(d->parent);
    free(d);
}

typedef struct
{
    int key;
    int val;
    int used;
} HEntry;

typedef struct
{
    HEntry *tab;
    int cap;
    int cnt;
} HMap;

static unsigned int hash_int_u(unsigned int x)
{
    x ^= x >> 16;
    x *= 0x7feb352dU;
    x ^= x >> 15;
    x *= 0x846ca68bU;
    x ^= x >> 16;
    return x;
}

static void hmap_init(HMap *m)
{
    m->cap = 16;
    m->cnt = 0;
    m->tab = (HEntry *)calloc(m->cap, sizeof(HEntry));
}

static void hmap_free(HMap *m)
{
    free(m->tab);
    m->tab = NULL;
    m->cap = m->cnt = 0;
}

static void hmap_rehash(HMap *m)
{
    int oldcap = m->cap;
    HEntry *old = m->tab;
    m->cap <<= 1;
    m->tab = (HEntry *)calloc(m->cap, sizeof(HEntry));
    m->cnt = 0;
    for (int i = 0; i < oldcap; i++)
    {
        if (old[i].used)
        {
            int key = old[i].key, val = old[i].val;
            unsigned int h = hash_int_u((unsigned int)key);
            int idx = (int)(h % (unsigned int)m->cap);
            while (m->tab[idx].used)
            {
                idx++;
                if (idx == m->cap)
                    idx = 0;
            }
            m->tab[idx].key = key;
            m->tab[idx].val = val;
            m->tab[idx].used = 1;
            m->cnt++;
        }
    }
    free(old);
}

static void hmap_set(HMap *m, int key, int val)
{
    if ((m->cnt + 1) * 10 >= m->cap * 7)
        hmap_rehash(m);
    unsigned int h = hash_int_u((unsigned int)key);
    int idx = (int)(h % (unsigned int)m->cap);
    while (m->tab[idx].used)
    {
        if (m->tab[idx].key == key)
        {
            m->tab[idx].val = val;
            return;
        }
        idx++;
        if (idx == m->cap)
            idx = 0;
    }
    m->tab[idx].key = key;
    m->tab[idx].val = val;
    m->tab[idx].used = 1;
    m->cnt++;
}

static int hmap_get(HMap *m, int key, int *out)
{
    unsigned int h = hash_int_u((unsigned int)key);
    int idx = (int)(h % (unsigned int)m->cap);
    for (;;)
    {
        if (!m->tab[idx].used)
            return 0;
        if (m->tab[idx].key == key)
        {
            *out = m->tab[idx].val;
            return 1;
        }
        idx++;
        if (idx == m->cap)
            idx = 0;
    }
}

int *avoidFlood(int *rain, int rainSize, int *returnSize)
{
    int n = rainSize;
    int *res = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        res[i] = 1;
    DSU *uf = dsu_create(n);
    HMap last;
    hmap_init(&last);
    for (int i = 0; i < n; i++)
    {
        int lake = rain[i];
        if (lake == 0)
            continue;
        res[i] = -1;
        dsu_unite_next(uf, i);
        int prev;
        if (hmap_get(&last, lake, &prev))
        {
            int dry = dsu_find(uf, prev + 1);
            if (dry >= i)
            {
                free(res);
                dsu_free(uf);
                hmap_free(&last);
                *returnSize = 0;
                return NULL;
            }
            res[dry] = lake;
            dsu_unite_next(uf, dry);
            hmap_set(&last, lake, i);
        }
        else
        {
            hmap_set(&last, lake, i);
        }
    }
    dsu_free(uf);
    hmap_free(&last);
    *returnSize = n;
    return res;
}
