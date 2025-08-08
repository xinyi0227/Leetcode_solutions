int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    int **res = (int **)malloc(n * sizeof(int *));
    int *colSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        res[i] = (int *)malloc(n * sizeof(int));
        colSizes[i] = n;
        for (int j = 0; j < n; ++j)
            res[i][j] = 0;
    }
    int x = 0, y = 0, dx = 1, dy = 0;
    for (int i = 0; i < n * n; ++i)
    {
        res[y][x] = i + 1;
        if (!(0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < n && res[y + dy][x + dx] == 0))
        {
            int temp = dx;
            dx = -dy;
            dy = temp;
        }
        x += dx;
        y += dy;
    }
    *returnSize = n;
    *returnColumnSizes = colSizes;
    return res;
}
