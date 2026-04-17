#include <stdbool.h>

bool canPartitionGrid(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    long long total = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            total += grid[i][j];
        }
    }

    if (total % 2 != 0)
        return false;

    long long target = total / 2;
    long long sum = 0;

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += grid[i][j];
        }
        if (sum == target)
            return true;
    }

    sum = 0;

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < m; i++)
        {
            sum += grid[i][j];
        }
        if (sum == target)
            return true;
    }

    return false;
}