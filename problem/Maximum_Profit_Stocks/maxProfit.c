#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Edge
{
    int to;
    int next;
};

struct Edge *edges;
int *head;
int edge_idx;

void add_edge(int u, int v)
{
    edges[edge_idx].to = v;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void dfs(int u, int *present, int *future, int ***dp, int budget)
{
    for (int i = head[u]; i != -1; i = edges[i].next)
    {
        int v = edges[i].to;
        dfs(v, present, future, dp, budget);
    }

    for (int parentBought = 0; parentBought <= 1; ++parentBought)
    {
        int price = parentBought ? present[u] / 2 : present[u];
        int profit = future[u] - price;

        int *curr = (int *)calloc(budget + 1, sizeof(int));

        // Option 1: don't buy u
        int *base = (int *)calloc(budget + 1, sizeof(int));

        for (int i = head[u]; i != -1; i = edges[i].next)
        {
            int v = edges[i].to;
            int *next = (int *)calloc(budget + 1, sizeof(int));

            for (int b1 = 0; b1 <= budget; ++b1)
            {
                if (base[b1] == 0 && b1 != 0)
                    continue;

                for (int b2 = 0; b1 + b2 <= budget; ++b2)
                {
                    next[b1 + b2] = MAX(next[b1 + b2], base[b1] + dp[v][0][b2]);
                }
            }
            free(base);
            base = next;
        }

        for (int b = 0; b <= budget; ++b)
        {
            curr[b] = MAX(curr[b], base[b]);
        }
        free(base);

        // Option 2: buy u
        if (price <= budget)
        {
            int *baseBuy = (int *)calloc(budget + 1, sizeof(int));

            for (int i = head[u]; i != -1; i = edges[i].next)
            {
                int v = edges[i].to;
                int *next = (int *)calloc(budget + 1, sizeof(int));

                for (int b1 = 0; b1 <= budget; ++b1)
                {
                    if (baseBuy[b1] == 0 && b1 != 0)
                        continue;

                    for (int b2 = 0; b1 + b2 <= budget; ++b2)
                    {
                        next[b1 + b2] = MAX(next[b1 + b2], baseBuy[b1] + dp[v][1][b2]);
                    }
                }
                free(baseBuy);
                baseBuy = next;
            }

            for (int b = price; b <= budget; ++b)
            {
                if (baseBuy[b - price] == 0 && (b - price) != 0)
                    continue;
                curr[b] = MAX(curr[b], baseBuy[b - price] + profit);
            }
            free(baseBuy);
        }

        free(dp[u][parentBought]);
        dp[u][parentBought] = curr;
    }
}

int maxProfit(int n, int *present, int presentSize, int *future, int futureSize, int **hierarchy, int hierarchySize, int *hierarchyColSize, int budget)
{
    head = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        head[i] = -1;

    edges = (struct Edge *)malloc(hierarchySize * sizeof(struct Edge));
    edge_idx = 0;

    for (int i = 0; i < hierarchySize; ++i)
    {
        add_edge(hierarchy[i][0] - 1, hierarchy[i][1] - 1);
    }

    int ***dp = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; ++i)
    {
        dp[i] = (int **)malloc(2 * sizeof(int *));
        dp[i][0] = (int *)calloc(budget + 1, sizeof(int));
        dp[i][1] = (int *)calloc(budget + 1, sizeof(int));
    }

    dfs(0, present, future, dp, budget);

    int ans = 0;
    for (int b = 0; b <= budget; ++b)
    {
        ans = MAX(ans, dp[0][0][b]);
    }

    free(head);
    free(edges);
    for (int i = 0; i < n; ++i)
    {
        free(dp[i][0]);
        free(dp[i][1]);
        free(dp[i]);
    }
    free(dp);

    return ans;
}