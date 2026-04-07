#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int *parent;
    int *rank;
    int components;
} DSU;

DSU *createDSU(int n)
{
    DSU *dsu = (DSU *)malloc(sizeof(DSU));
    dsu->parent = (int *)malloc(n * sizeof(int));
    dsu->rank = (int *)calloc(n, sizeof(int));
    dsu->components = n;
    for (int i = 0; i < n; i++)
        dsu->parent[i] = i;
    return dsu;
}

void freeDSU(DSU *dsu)
{
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
}

int find(DSU *dsu, int x)
{
    if (dsu->parent[x] != x)
        dsu->parent[x] = find(dsu, dsu->parent[x]);
    return dsu->parent[x];
}

bool unite(DSU *dsu, int a, int b)
{
    a = find(dsu, a);
    b = find(dsu, b);
    if (a == b)
        return false;
    if (dsu->rank[a] < dsu->rank[b])
    {
        int temp = a;
        a = b;
        b = temp;
    }
    dsu->parent[b] = a;
    if (dsu->rank[a] == dsu->rank[b])
        dsu->rank[a]++;
    dsu->components--;
    return true;
}

bool canAchieve(int n, int **edges, int edgesSize, int k, int x)
{
    DSU *dsu = createDSU(n);
    for (int i = 0; i < edgesSize; i++)
    {
        if (edges[i][3] == 1)
        {
            if (edges[i][2] < x || !unite(dsu, edges[i][0], edges[i][1]))
            {
                freeDSU(dsu);
                return false;
            }
        }
    }
    for (int i = 0; i < edgesSize; i++)
    {
        if (edges[i][3] == 0 && edges[i][2] >= x)
        {
            unite(dsu, edges[i][0], edges[i][1]);
        }
    }
    int usedUpgrades = 0;
    for (int i = 0; i < edgesSize; i++)
    {
        if (edges[i][3] == 0 && edges[i][2] < x && 2 * edges[i][2] >= x)
        {
            if (unite(dsu, edges[i][0], edges[i][1]))
            {
                usedUpgrades++;
            }
        }
    }
    bool res = (dsu->components == 1 && usedUpgrades <= k);
    freeDSU(dsu);
    return res;
}

int maxStability(int n, int **edges, int edgesSize, int *edgesColSize, int k)
{
    DSU *dsu = createDSU(n);
    for (int i = 0; i < edgesSize; i++)
    {
        if (edges[i][3] == 1)
        {
            if (!unite(dsu, edges[i][0], edges[i][1]))
            {
                freeDSU(dsu);
                return -1;
            }
        }
    }
    freeDSU(dsu);

    int low = 1, high = 200000, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canAchieve(n, edges, edgesSize, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}