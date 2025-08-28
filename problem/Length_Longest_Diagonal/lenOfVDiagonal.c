int DIRS[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

int dfs(int i, int j, int k, int canTurn, int target, int **grid, int m, int n, int ***memo)
{
    i += DIRS[k][0];
    j += DIRS[k][1];
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != target)
    {
        return 0;
    }
    int mask = (k << 1) | canTurn;
    if (memo[i][j][mask] > 0)
        return memo[i][j][mask];

    int res = dfs(i, j, k, canTurn, 2 - target, grid, m, n, memo);
    if (canTurn == 1)
    {
        int maxs[4] = {m - i - 1, j, i, n - j - 1};
        int nk = (k + 1) % 4;
        if (maxs[nk] > res)
        {
            int temp = dfs(i, j, nk, 0, 2 - target, grid, m, n, memo);
            res = res > temp ? res : temp;
        }
    }
    return memo[i][j][mask] = res + 1;
}

int lenOfVDiagonal(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int ***memo = (int ***)malloc(m * sizeof(int **));
    for (int i = 0; i < m; i++)
    {
        memo[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = (int *)calloc(8, sizeof(int));
        }
    }
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 1)
                continue;
            int maxs[4] = {m - i, j + 1, i + 1, n - j};
            for (int k = 0; k < 4; k++)
            {
                if (maxs[k] > ans)
                {
                    int temp = dfs(i, j, k, 1, 2, grid, m, n, memo) + 1;
                    ans = ans > temp ? ans : temp;
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            free(memo[i][j]);
        }
        free(memo[i]);
    }
    free(memo);

    return ans;
}
