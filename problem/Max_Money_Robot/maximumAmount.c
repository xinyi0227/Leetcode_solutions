#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumAmount(int **coins, int coinsSize, int *coinsColSize)
{
    int n = coinsSize;
    int m = coinsColSize[0];
    int INF = 1e9;

    int ***dp = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++)
    {
        dp[i] = (int **)malloc(m * sizeof(int *));
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = (int *)malloc(3 * sizeof(int));
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = -INF;
        }
    }

    dp[0][0][0] = coins[0][0];
    dp[0][0][1] = 0;
    dp[0][0][2] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i > 0)
                {
                    dp[i][j][k] = MAX(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                    if (k > 0)
                    {
                        dp[i][j][k] = MAX(dp[i][j][k], dp[i - 1][j][k - 1]);
                    }
                }
                if (j > 0)
                {
                    dp[i][j][k] = MAX(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                    if (k > 0)
                    {
                        dp[i][j][k] = MAX(dp[i][j][k], dp[i][j - 1][k - 1]);
                    }
                }
            }
        }
    }

    int ans = dp[n - 1][m - 1][0];
    for (int k = 1; k < 3; k++)
    {
        ans = MAX(ans, dp[n - 1][m - 1][k]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            free(dp[i][j]);
        free(dp[i]);
    }
    free(dp);

    return ans;
}