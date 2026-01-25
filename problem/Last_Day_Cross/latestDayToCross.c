#include <stdlib.h>
#include <string.h>

typedef struct
{
    int r, c;
} Node;

static int isPossible(int m, int n, int t, int **cells)
{
    int size = (m + 1) * (n + 1);
    unsigned char *grid = (unsigned char *)calloc(size, 1);
    if (!grid)
        return 0;

    for (int i = 0; i < t; i++)
    {
        int r = cells[i][0], c = cells[i][1];
        grid[r * (n + 1) + c] = 1;
    }

    Node *q = (Node *)malloc(sizeof(Node) * (m * n + 5));
    int head = 0, tail = 0;

    for (int c = 1; c <= n; c++)
    {
        if (grid[1 * (n + 1) + c] == 0)
        {
            q[tail++] = (Node){1, c};
            grid[1 * (n + 1) + c] = 1;
        }
    }

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (head < tail)
    {
        Node cur = q[head++];
        for (int k = 0; k < 4; k++)
        {
            int nr = cur.r + dr[k], nc = cur.c + dc[k];
            if (nr > 0 && nc > 0 && nr <= m && nc <= n && grid[nr * (n + 1) + nc] == 0)
            {
                grid[nr * (n + 1) + nc] = 1;
                if (nr == m)
                {
                    free(q);
                    free(grid);
                    return 1;
                }
                q[tail++] = (Node){nr, nc};
            }
        }
    }

    free(q);
    free(grid);
    return 0;
}

int latestDayToCross(int row, int col, int **cells, int cellsSize, int *cellsColSize)
{
    int left = 0, right = row * col, ans = 0;
    while (left < right - 1)
    {
        int mid = left + (right - left) / 2;
        if (isPossible(row, col, mid, cells))
        {
            left = mid;
            ans = mid;
        }
        else
        {
            right = mid;
        }
    }
    return ans;
}