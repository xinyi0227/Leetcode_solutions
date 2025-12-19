int numberOfPaths(int **grid, int gridSize, int *gridColSize, int k)
{
    const int MOD = 1000000007;
    int m = gridSize, n = gridColSize[0];
    int *prev = malloc(n * k * sizeof(int));
    int *curr = malloc(n * k * sizeof(int));
    memset(prev, 0, n * k * sizeof(int));
    memset(curr, 0, n * k * sizeof(int));
    int sum = 0;

    for (int j = 0; j < n; j++)
    {
        sum = (sum + grid[0][j]) % k;
        prev[j * k + sum] = 1;
    }

    sum = grid[0][0] % k;
    for (int i = 1; i < m; i++)
    {
        sum = (sum + grid[i][0]) % k;
        memset(curr, 0, n * k * sizeof(int));
        curr[0 * k + sum] = 1;

        for (int j = 1; j < n; j++)
        {
            int val = grid[i][j];
            for (int r = 0; r < k; r++)
            {
                int nr = (r + val) % k;
                curr[j * k + nr] = (prev[j * k + r] + curr[(j - 1) * k + r]) % MOD;
            }
        }

        int *temp = prev;
        prev = curr;
        curr = temp;
    }

    int result = prev[(n - 1) * k + 0];
    free(prev);
    free(curr);
    return result;
}
