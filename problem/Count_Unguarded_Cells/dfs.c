void dfs(int r, int c, char dir, int **vis, int **mp, int m, int n)
{
    if (r < 0 || c < 0 || r >= m || c >= n)
        return;
    if (mp[r][c])
        return;
    vis[r][c] = 1;

    if (dir == 'r')
    {
        dfs(r, c + 1, 'r', vis, mp, m, n);
    }
    if (dir == 'l')
    {
        dfs(r, c - 1, 'l', vis, mp, m, n);
    }
    if (dir == 'u')
    {
        dfs(r - 1, c, 'u', vis, mp, m, n);
    }
    if (dir == 'd')
    {
        dfs(r + 1, c, 'd', vis, mp, m, n);
    }
}

int countUnguarded(int m, int n, int **guards, int guardsSize, int *guardsColSize, int **walls, int wallsSize, int *wallsColSize)
{
    int **vis = (int **)malloc(m * sizeof(int *));
    int **mp = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        vis[i] = (int *)calloc(n, sizeof(int));
        mp[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < guardsSize; i++)
    {
        int r = guards[i][0];
        int c = guards[i][1];
        mp[r][c] = 1;
        vis[r][c] = 1;
    }

    for (int i = 0; i < wallsSize; i++)
    {
        int r = walls[i][0];
        int c = walls[i][1];
        mp[r][c] = 1;
        vis[r][c] = 1;
    }

    for (int i = 0; i < guardsSize; i++)
    {
        int r = guards[i][0];
        int c = guards[i][1];
        dfs(r, c + 1, 'r', vis, mp, m, n);
        dfs(r, c - 1, 'l', vis, mp, m, n);
        dfs(r + 1, c, 'd', vis, mp, m, n);
        dfs(r - 1, c, 'u', vis, mp, m, n);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0)
                cnt++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        free(vis[i]);
        free(mp[i]);
    }
    free(vis);
    free(mp);

    return cnt;
}