#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e15

long long min_ll(long long a, long long b) { return a < b ? a : b; }

long long minimumCost(char *source, char *target, char **original, int originalSize, char **changed, int changedSize, int *cost, int costSize)
{
    int n = strlen(source);
    char *dict[405];
    int sz = 0;
    int lengths[405], l_cnt = 0;

    for (int i = 0; i < originalSize; i++)
    {
        int u = -1, v = -1;
        for (int j = 0; j < sz; j++)
        {
            if (strcmp(original[i], dict[j]) == 0)
                u = j;
            if (strcmp(changed[i], dict[j]) == 0)
                v = j;
        }
        if (u == -1)
        {
            dict[sz] = original[i];
            int len = strlen(original[i]);
            int found = 0;
            for (int k = 0; k < l_cnt; k++)
                if (lengths[k] == len)
                    found = 1;
            if (!found)
                lengths[l_cnt++] = len;
            u = sz++;
        }
        if (v == -1)
        {
            dict[sz] = changed[i];
            v = sz++;
        }
    }

    long long dist[405][405];
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
            dist[i][j] = (i == j) ? 0 : INF;
    }

    for (int i = 0; i < originalSize; i++)
    {
        int u = -1, v = -1;
        for (int j = 0; j < sz; j++)
        {
            if (strcmp(original[i], dict[j]) == 0)
                u = j;
            if (strcmp(changed[i], dict[j]) == 0)
                v = j;
        }
        dist[u][v] = min_ll(dist[u][v], (long long)cost[i]);
    }

    for (int k = 0; k < sz; k++)
    {
        for (int i = 0; i < sz; i++)
        {
            if (dist[i][k] == INF)
                continue;
            for (int j = 0; j < sz; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    for (int i = 0; i <= n; i++)
        dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == INF)
            continue;
        if (source[i] == target[i])
            dp[i + 1] = min_ll(dp[i + 1], dp[i]);

        for (int l = 0; l < l_cnt; l++)
        {
            int L = lengths[l];
            if (i + L > n)
                continue;

            int u = -1, v = -1;
            for (int j = 0; j < sz; j++)
            {
                if (strlen(dict[j]) == L)
                {
                    if (u == -1 && strncmp(source + i, dict[j], L) == 0)
                        u = j;
                    if (v == -1 && strncmp(target + i, dict[j], L) == 0)
                        v = j;
                }
            }

            if (u != -1 && v != -1 && dist[u][v] != INF)
            {
                dp[i + L] = min_ll(dp[i + L], dp[i] + dist[u][v]);
            }
        }
    }

    long long res = dp[n];
    free(dp);
    return res >= INF ? -1 : res;
}