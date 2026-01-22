int countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int i = m - 1;
    int j = 0;
    int res = 0;

    while (i >= 0 && j < n)
    {
        if (grid[i][j] < 0)
        {
            res += n - j;
            i--;
        }
        else
        {
            j++;
        }
    }

    return res;
}