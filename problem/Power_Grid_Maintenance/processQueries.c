#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *data;
    int size;
    int cap;
} MinHeap;

static void heap_init(MinHeap *h, int cap)
{
    h->data = (int *)malloc(sizeof(int) * (cap > 0 ? cap : 1));
    h->size = 0;
    h->cap = (cap > 0 ? cap : 1);
}
static void heap_free(MinHeap *h)
{
    free(h->data);
}
static void heap_ensure(MinHeap *h)
{
    if (h->size == h->cap)
    {
        h->cap = h->cap ? h->cap * 2 : 4;
        h->data = (int *)realloc(h->data, sizeof(int) * h->cap);
    }
}
static void heap_push(MinHeap *h, int x)
{
    heap_ensure(h);
    int i = h->size++;
    h->data[i] = x;
    while (i)
    {
        int p = (i - 1) >> 1;
        if (h->data[p] <= h->data[i])
            break;
        int t = h->data[p];
        h->data[p] = h->data[i];
        h->data[i] = t;
        i = p;
    }
}
static int heap_top(MinHeap *h) { return h->data[0]; }
static void heap_pop(MinHeap *h)
{
    if (h->size == 0)
        return;
    int n = --h->size;
    if (n == 0)
        return;
    h->data[0] = h->data[n];
    int i = 0;
    while (1)
    {
        int l = i * 2 + 1, r = l + 1, b = i;
        if (l < h->size && h->data[l] < h->data[b])
            b = l;
        if (r < h->size && h->data[r] < h->data[b])
            b = r;
        if (b == i)
            break;
        int t = h->data[i];
        h->data[i] = h->data[b];
        h->data[b] = t;
        i = b;
    }
}

typedef struct
{
    MinHeap *heaps;
    int heapsN;
    int *parent;
    int *sz;
    int *offline;
    int n;
} DSUEnv;

static void env_init(DSUEnv *e, int c)
{
    e->n = c;
    e->parent = (int *)malloc(sizeof(int) * c);
    e->sz = (int *)malloc(sizeof(int) * c);
    e->offline = (int *)calloc(c, sizeof(int));
    e->heaps = (MinHeap *)malloc(sizeof(MinHeap) * c);
    e->heapsN = c;
    for (int i = 0; i < c; i++)
    {
        e->parent[i] = i;
        e->sz[i] = 1;
        heap_init(&e->heaps[i], 1);
        heap_push(&e->heaps[i], i);
    }
}
static void env_free(DSUEnv *e)
{
    for (int i = 0; i < e->heapsN; i++)
        heap_free(&e->heaps[i]);
    free(e->heaps);
    free(e->parent);
    free(e->sz);
    free(e->offline);
}
static int findp(DSUEnv *e, int x)
{
    if (e->parent[x] == x)
        return x;
    e->parent[x] = findp(e, e->parent[x]);
    return e->parent[x];
}
static void merge_heaps(MinHeap *to, MinHeap *from)
{
    for (int i = 0; i < from->size; i++)
        heap_push(to, from->data[i]);
    from->size = 0;
}
static void dsu_union(DSUEnv *e, int u, int v)
{
    int up = findp(e, u);
    int vp = findp(e, v);
    if (up == vp)
        return;
    if (e->sz[up] > e->sz[vp])
    {
        e->sz[up] += e->sz[vp];
        e->parent[vp] = up;
        merge_heaps(&e->heaps[up], &e->heaps[vp]);
    }
    else
    {
        e->sz[vp] += e->sz[up];
        e->parent[up] = vp;
        merge_heaps(&e->heaps[vp], &e->heaps[up]);
    }
}

int *processQueries(int c, int **connections, int connectionsSize, int *connectionsColSize, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    DSUEnv E;
    env_init(&E, c);

    for (int i = 0; i < connectionsSize; i++)
    {
        int u = connections[i][0] - 1;
        int v = connections[i][1] - 1;
        dsu_union(&E, u, v);
    }

    int *ans = (int *)malloc(sizeof(int) * queriesSize);
    int an = 0;

    for (int i = 0; i < queriesSize; i++)
    {
        int type = queries[i][0];
        int node = queries[i][1] - 1;
        if (type == 1)
        {
            if (E.offline[node] == 0)
            {
                ans[an++] = node + 1;
                continue;
            }
            int p = findp(&E, node);
            while (E.heaps[p].size > 0 && E.offline[heap_top(&E.heaps[p])])
                heap_pop(&E.heaps[p]);
            if (E.heaps[p].size == 0)
                ans[an++] = -1;
            else
                ans[an++] = heap_top(&E.heaps[p]) + 1;
        }
        else
        {
            E.offline[node] = 1;
        }
    }

    *returnSize = an;
    env_free(&E);
    return ans;
}