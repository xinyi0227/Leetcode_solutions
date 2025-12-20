#include <stdlib.h>

int ans;
int **adj;
int *adjSize;
int *visited;

long long dfs(int i, int *values, int k)
{
    visited[i] = 1;
    long long sum = values[i];
    for (int idx = 0; idx < adjSize[i]; idx++)
    {
        int j = adj[i][idx];
        if (visited[j])
            continue;
        sum += dfs(j, values, k);
        sum %= k;
    }
    if (sum % k == 0)
    {
        ans++;
        return 0;
    }
    return sum;
}

int maxKDivisibleComponents(
    int n,
    int **edges,
    int edgesSize,
    int *edgesColSize,
    int *values,
    int valuesSize,
    int k)
{
    ans = 0;
    adj = (int **)malloc(n * sizeof(int *));
    adjSize = (int *)calloc(n, sizeof(int));
    visited = (int *)calloc(n, sizeof(int));

    for (int e = 0; e < edgesSize; e++)
    {
        int u = edges[e][0];
        int v = edges[e][1];
        adjSize[u]++;
        adjSize[v]++;
    }

    for (int i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int e = 0; e < edgesSize; e++)
    {
        int u = edges[e][0];
        int v = edges[e][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    dfs(0, values, k);

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);
    free(adjSize);
    free(visited);

    return ans;
}
