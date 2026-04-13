int numberOfSubmatrices(char **grid, int gridSize, int *gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];
    int *sumX = (int *)calloc(cols, sizeof(int));
    int *sumY = (int *)calloc(cols, sizeof(int));
    int res = 0;

    for (int i = 0; i < rows; i++)
    {
        int rx = 0, ry = 0;
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 'X')
                rx++;
            else if (grid[i][j] == 'Y')
                ry++;
            sumX[j] += rx;
            sumY[j] += ry;
            if (sumX[j] > 0 && sumX[j] == sumY[j])
                res++;
        }
    }

    free(sumX);
    free(sumY);
    return res;
}