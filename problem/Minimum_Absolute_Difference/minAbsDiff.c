int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int **minAbsDiff(int **grid, int gridSize, int *gridColSize, int k, int *returnSize, int **returnColumnSizes)
{
    int m = gridSize;
    int n = gridColSize[0];
    int rows = m - k + 1;
    int cols = n - k + 1;

    *returnSize = rows;
    *returnColumnSizes = (int *)malloc(rows * sizeof(int));
    int **ans = (int **)malloc(rows * sizeof(int *));

    int *v = (int *)malloc(k * k * sizeof(int));

    for (int i = 0; i < rows; i++)
    {
        ans[i] = (int *)malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;
        for (int j = 0; j < cols; j++)
        {
            int idx = 0;
            for (int x = i; x < i + k; x++)
            {
                for (int y = j; y < j + k; y++)
                {
                    v[idx++] = grid[x][y];
                }
            }

            qsort(v, idx, sizeof(int), compare);

            int uniqueSize = 0;
            if (idx > 0)
            {
                uniqueSize = 1;
                for (int p = 1; p < idx; p++)
                {
                    if (v[p] != v[p - 1])
                    {
                        v[uniqueSize++] = v[p];
                    }
                }
            }

            if (uniqueSize <= 1)
            {
                ans[i][j] = 0;
            }
            else
            {
                int mn = 2147483647;
                for (int p = 0; p < uniqueSize - 1; p++)
                {
                    int diff = v[p + 1] - v[p];
                    if (diff < mn)
                        mn = diff;
                }
                ans[i][j] = mn;
            }
        }
    }
    free(v);
    return ans;
}