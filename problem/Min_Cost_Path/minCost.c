#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long u64;

typedef struct Edge
{
    int to;
    int weight;
    struct Edge *next;
} Edge;

typedef struct
{
    u64 *data;
    int size;
    int capacity;
} MinHeap;

MinHeap *createHeap(int cap)
{
    MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
    h->data = (u64 *)malloc(sizeof(u64) * (cap + 1));
    h->size = 0;
    h->capacity = cap;
    return h;
}

void push(MinHeap *h, u64 val)
{
    int i = ++h->size;
    while (i > 1 && h->data[i >> 1] > val)
    {
        h->data[i] = h->data[i >> 1];
        i >>= 1;
    }
    h->data[i] = val;
}

u64 pop(MinHeap *h)
{
    u64 ret = h->data[1];
    u64 last = h->data[h->size--];
    int i = 1, child = 2;
    while (child <= h->size)
    {
        if (child < h->size && h->data[child + 1] < h->data[child])
            child++;
        if (last <= h->data[child])
            break;
        h->data[i] = h->data[child];
        i = child;
        child <<= 1;
    }
    h->data[i] = last;
    return ret;
}

int minCost(int n, int **edges, int edgesSize, int *edgesColSize)
{
    Edge **adj = (Edge **)calloc(n, sizeof(Edge *));
    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        Edge *e1 = (Edge *)malloc(sizeof(Edge));
        e1->to = v;
        e1->weight = w;
        e1->next = adj[u];
        adj[u] = e1;
        Edge *e2 = (Edge *)malloc(sizeof(Edge));
        e2->to = u;
        e2->weight = w * 2;
        e2->next = adj[v];
        adj[v] = e2;
    }

    unsigned *dist = (unsigned *)malloc(sizeof(unsigned) * n);
    memset(dist, 255, sizeof(unsigned) * n);

    MinHeap *pq = createHeap(edgesSize * 2 + n);

    dist[0] = 0;
    push(pq, 0);

    int res = -1;

    while (pq->size > 0)
    {
        u64 curr = pop(pq);
        unsigned d = curr >> 16;
        int u = curr & 0xFFFF;

        if (d > dist[u])
            continue;
        if (u == n - 1)
        {
            res = d;
            break;
        }

        for (Edge *e = adj[u]; e; e = e->next)
        {
            unsigned d2 = d + e->weight;
            if (d2 < dist[e->to])
            {
                dist[e->to] = d2;
                push(pq, ((u64)d2 << 16) | e->to);
            }
        }
    }

    return res;
}