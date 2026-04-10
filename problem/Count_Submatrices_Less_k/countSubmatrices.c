int countSubmatrices(int **grid, int gridSize, int *gridColSize, int k)
{
    int ans = 0;
    int m = gridSize;
    int n = gridColSize[0];

    int **px = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
    {
        px[i] = (int *)calloc((n + 1), sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            px[i + 1][j + 1] = grid[i][j] + px[i][j + 1] + px[i + 1][j] - px[i][j];
            if (px[i + 1][j + 1] <= k)
            {
                ans++;
            }
        }
    }

    for (int i = 0; i <= m; i++)
    {
        free(px[i]);
    }
    free(px);

    return ans;
}