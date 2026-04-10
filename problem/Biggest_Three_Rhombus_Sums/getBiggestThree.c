#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int *getBiggestThree(int **grid, int gridSize, int *gridColSize, int *returnSize)
{
    int m = gridSize, n = gridColSize[0];
    int **diag1 = (int **)malloc((m + 1) * sizeof(int *));
    int **diag2 = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
    {
        diag1[i] = (int *)calloc(n + 1, sizeof(int));
        diag2[i] = (int *)calloc(n + 2, sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
            diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
        }
    }

    int *uniqueSums = (int *)malloc(m * n * m * sizeof(int));
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            uniqueSums[count++] = grid[i][j];
            for (int k = 1; i - k >= 0 && i + k < m && j - k >= 0 && j + k < n; k++)
            {
                int topR = i - k, topC = j;
                int rightR = i, rightC = j + k;
                int bottomR = i + k, bottomC = j;
                int leftR = i, leftC = j - k;

                long long border = 0;
                border += diag1[rightR + 1][rightC + 1] - diag1[topR][topC];
                border += diag2[bottomR + 1][bottomC] - diag2[rightR][rightC + 1];
                border += diag1[bottomR + 1][bottomC + 1] - diag1[leftR][leftC];
                border += diag2[leftR + 1][leftC] - diag2[topR][topC + 1];
                border -= (grid[topR][topC] + grid[rightR][rightC] + grid[bottomR][bottomC] + grid[leftR][leftC]);
                uniqueSums[count++] = (int)border;
            }
        }
    }

    qsort(uniqueSums, count, sizeof(int), compare);

    int *res = (int *)malloc(3 * sizeof(int));
    int resIdx = 0;
    for (int i = 0; i < count && resIdx < 3; i++)
    {
        if (resIdx == 0 || uniqueSums[i] != uniqueSums[i - 1])
        {
            res[resIdx++] = uniqueSums[i];
        }
    }

    for (int i = 0; i <= m; i++)
    {
        free(diag1[i]);
        free(diag2[i]);
    }
    free(diag1);
    free(diag2);
    free(uniqueSums);

    *returnSize = resIdx;
    return res;
}