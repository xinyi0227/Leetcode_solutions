#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define M 10001
#define NN 6400
#define INF 1000000007

unsigned dp[11][NN];
unsigned suffixMin[M];
int head[M];
int next_node[NN];
int grid_vals[NN];

inline int min_val(unsigned a, unsigned b)
{
    return a < b ? a : b;
}

inline int idx(int i, int j, int c)
{
    return i * c + j;
}

int minCost(int **grid, int gridSize, int *gridColSize, int k)
{
    int r = gridSize;
    int c = gridColSize[0];
    int N = r * c;
    int xMax = 0;

    for (int i = 0; i < M; i++)
        head[i] = -1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int x = grid[i][j];
            int pos = idx(i, j, c);
            if (x > xMax)
                xMax = x;

            next_node[pos] = head[x];
            head[x] = pos;
        }
    }

    for (int t = 0; t <= k; t++)
    {
        for (int i = 0; i < N; i++)
            dp[t][i] = INF;
    }

    dp[0][0] = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int pos = idx(i, j, c);
            int x = grid[i][j];
            if (i > 0)
            {
                unsigned prev = dp[0][idx(i - 1, j, c)];
                if (prev != INF)
                    dp[0][pos] = min_val(dp[0][pos], prev + x);
            }
            if (j > 0)
            {
                unsigned prev = dp[0][idx(i, j - 1, c)];
                if (prev != INF)
                    dp[0][pos] = min_val(dp[0][pos], prev + x);
            }
        }
    }

    for (int t = 1; t <= k; t++)
    {
        unsigned currMin = INF;
        for (int x = xMax; x >= 0; x--)
        {
            int pos = head[x];
            while (pos != -1)
            {
                currMin = min_val(currMin, dp[t - 1][pos]);
                pos = next_node[pos];
            }
            suffixMin[x] = currMin;
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int pos = idx(i, j, c);
                int x = grid[i][j];

                dp[t][pos] = min_val(dp[t - 1][pos], suffixMin[x]);

                if (i > 0)
                {
                    unsigned prev = dp[t][idx(i - 1, j, c)];
                    if (prev != INF)
                        dp[t][pos] = min_val(dp[t][pos], prev + x);
                }
                if (j > 0)
                {
                    unsigned prev = dp[t][idx(i, j - 1, c)];
                    if (prev != INF)
                        dp[t][pos] = min_val(dp[t][pos], prev + x);
                }
            }
        }
    }

    return dp[k][N - 1];
}