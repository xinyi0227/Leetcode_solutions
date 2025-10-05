static int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

static void dfs(int i, int j, int **heights, int m, int n, char *vis)
{
    vis[i * n + j] = 1;
    for (int d = 0; d < 4; d++)
    {
        int x = i + dirs[d][0], y = j + dirs[d][1];
        if (x < 0 || x >= m || y < 0 || y >= n)
            continue;
        if (vis[x * n + y])
            continue;
        if (heights[x][y] < heights[i][j])
            continue;
        dfs(x, y, heights, m, n, vis);
    }
}

int **pacificAtlantic(int **heights, int heightsSize, int *heightsColSize, int *returnSize, int **returnColumnSizes)
{
    int m = heightsSize;
    if (m == 0)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int n = heightsColSize[0];
    char *pac = (char *)calloc(m * n, 1);
    char *atl = (char *)calloc(m * n, 1);

    for (int j = 0; j < n; j++)
        dfs(0, j, heights, m, n, pac);
    for (int i = 0; i < m; i++)
        dfs(i, 0, heights, m, n, pac);
    for (int j = 0; j < n; j++)
        dfs(m - 1, j, heights, m, n, atl);
    for (int i = 0; i < m; i++)
        dfs(i, n - 1, heights, m, n, atl);

    int cnt = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (pac[i * n + j] && atl[i * n + j])
                cnt++;

    int **ans = (int **)malloc(cnt * sizeof(int *));
    *returnColumnSizes = (int *)malloc(cnt * sizeof(int));
    *returnSize = cnt;

    int t = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (pac[i * n + j] && atl[i * n + j])
            {
                ans[t] = (int *)malloc(2 * sizeof(int));
                ans[t][0] = i;
                ans[t][1] = j;
                (*returnColumnSizes)[t] = 2;
                t++;
            }

    free(pac);
    free(atl);
    return ans;
}
