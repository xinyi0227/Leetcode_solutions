#include <stdint.h>
#include <math.h>

#define MOD 1000000007

int maxProductPath(int **grid, int gridSize, int *gridColSize)
{
    int r = gridSize, c = gridColSize[0];
    long long dp[2][15][2];

    long long p = grid[0][0];
    dp[0][0][0] = dp[0][0][1] = p;

    for (int j = 1; j < c; j++)
    {
        p *= grid[0][j];
        dp[0][j][0] = dp[0][j][1] = p;
    }

    p = grid[0][0];
    for (int i = 1; i < r; i++)
    {
        int isOdd = i & 1, prv = !isOdd;
        p *= grid[i][0];
        dp[isOdd][0][0] = dp[isOdd][0][1] = p;

        for (int j = 1; j < c; j++)
        {
            long long x = grid[i][j];
            long long vals[4] = {
                x * dp[isOdd][j - 1][0], x * dp[isOdd][j - 1][1],
                x * dp[prv][j][0], x * dp[prv][j][1]};
            long long minV = vals[0], maxV = vals[0];
            for (int k = 1; k < 4; k++)
            {
                if (vals[k] < minV)
                    minV = vals[k];
                if (vals[k] > maxV)
                    maxV = vals[k];
            }
            dp[isOdd][j][0] = minV;
            dp[isOdd][j][1] = maxV;
        }
    }

    long long ans = dp[(r - 1) & 1][c - 1][1];
    return ans < 0 ? -1 : (int)(ans % MOD);
}