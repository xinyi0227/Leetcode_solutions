#include <string.h>
#include <limits.h>

long long minimumCost(char *source, char *target, char *original, int originalSize, char *changed, int changedSize, int *cost, int costSize)
{
    long long dist[26][26];
    const long long INF = 1e14;

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < originalSize; ++i)
    {
        int u = original[i] - 'a';
        int v = changed[i] - 'a';
        if ((long long)cost[i] < dist[u][v])
        {
            dist[u][v] = (long long)cost[i];
        }
    }

    for (int k = 0; k < 26; ++k)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (dist[i][k] == INF)
                continue;
            for (int j = 0; j < 26; ++j)
            {
                if (dist[k][j] != INF)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    long long totalCost = 0;
    int n = strlen(source);

    for (int i = 0; i < n; ++i)
    {
        int u = source[i] - 'a';
        int v = target[i] - 'a';
        if (u == v)
            continue;
        if (dist[u][v] == INF)
            return -1;
        totalCost += dist[u][v];
    }

    return totalCost;
}