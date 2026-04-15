#include <stdlib.h>

int **constructProductMatrix(int **grid, int gridSize, int *gridColSize, int *returnSize, int **returnColumnSizes)
{
    int n = gridSize;
    int m = gridColSize[0];
    const int MOD = 12345;

    int **p = (int **)malloc(n * sizeof(int *));
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    *returnSize = n;

    for (int i = 0; i < n; i++)
    {
        p[i] = (int *)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }

    long long suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            p[i][j] = (int)suffix;
            suffix = (suffix * (grid[i][j] % MOD)) % MOD;
        }
    }

    long long prefix = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p[i][j] = (int)((p[i][j] * prefix) % MOD);
            prefix = (prefix * (grid[i][j] % MOD)) % MOD;
        }
    }

    return p;
}