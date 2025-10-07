#include <stdlib.h>

static int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

static int dfs_c(int x, int y, int t, int **grid, int n, unsigned char *vis)
{
    if (x == n - 1 && y == n - 1)
        return 1;
    vis[x * n + y] = 1;
    for (int k = 0; k < 4; ++k)
    {
        int nx = x + dirs[k][0], ny = y + dirs[k][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (!vis[nx * n + ny] && grid[nx][ny] <= t)
            {
                if (dfs_c(nx, ny, t, grid, n, vis))
                    return 1;
            }
        }
    }
    return 0;
}

int swimInWater(int **grid, int gridSize, int *gridColSize)
{
    int n = gridSize;
    int low = 0, high = n * n - 1, ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (grid[0][0] <= mid)
        {
            unsigned char *vis = (unsigned char *)calloc(n * n, 1);
            int ok = dfs_c(0, 0, mid, grid, n, vis);
            free(vis);
            if (ok)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
