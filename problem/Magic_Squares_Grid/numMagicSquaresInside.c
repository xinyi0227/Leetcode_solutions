#include <stdbool.h>
#include <string.h>

bool isValid(int i, int j, int **grid)
{
    int count[10] = {0};
    for (int x = 0; x < 3; ++x)
    {
        for (int y = 0; y < 3; ++y)
        {
            int num = grid[i + x][j + y];
            if (num < 1 || num > 9 || count[num] > 0)
                return false;
            count[num]++;
        }
    }

    int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

    for (int x = 0; x < 3; ++x)
    {
        if (sum != (grid[i + x][j] + grid[i + x][j + 1] + grid[i + x][j + 2]))
            return false;
    }

    for (int y = 0; y < 3; ++y)
    {
        if (sum != (grid[i][j + y] + grid[i + 1][j + y] + grid[i + 2][j + y]))
            return false;
    }

    if (sum != (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]))
        return false;
    if (sum != (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2]))
        return false;

    return true;
}

int numMagicSquaresInside(int **grid, int gridSize, int *gridColSize)
{
    int cnt = 0;
    int row = gridSize;
    int col = gridColSize[0];

    if (row < 3 || col < 3)
        return 0;

    for (int i = 0; i <= row - 3; ++i)
    {
        for (int j = 0; j <= col - 3; ++j)
        {
            if (isValid(i, j, grid))
                cnt++;
        }
    }
    return cnt;
}