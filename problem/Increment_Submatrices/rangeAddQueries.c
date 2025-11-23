#include <stdlib.h>

int **rangeAddQueries(int n, int **queries, int queriesSize, int *queriesColSize, int *returnSize, int **returnColumnSizes)
{
    int **diff = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        diff[i] = (int *)calloc(n, sizeof(int));
    }

    for (int qi = 0; qi < queriesSize; qi++)
    {
        int r1 = queries[qi][0], c1 = queries[qi][1], r2 = queries[qi][2], c2 = queries[qi][3];
        diff[r1][c1] += 1;
        if (c2 + 1 < n)
            diff[r1][c2 + 1] -= 1;
        if (r2 + 1 < n)
            diff[r2 + 1][c1] -= 1;
        if (r2 + 1 < n && c2 + 1 < n)
            diff[r2 + 1][c2 + 1] += 1;
    }

    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = diff[i][j];
            if (i > 0)
                val += result[i - 1][j];
            if (j > 0)
                val += result[i][j - 1];
            if (i > 0 && j > 0)
                val -= result[i - 1][j - 1];
            result[i][j] = val;
        }
    }

    for (int i = 0; i < n; i++)
        free(diff[i]);
    free(diff);

    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        (*returnColumnSizes)[i] = n;

    return result;
}