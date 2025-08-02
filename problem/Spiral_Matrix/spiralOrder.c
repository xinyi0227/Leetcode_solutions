int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    if (matrixSize == 0 || matrixColSize[0] == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total = rows * cols;
    *returnSize = total;

    int *res = (int *)malloc(total * sizeof(int));
    if (!res)
        return NULL;

    int x = 0, y = 0;
    int dx = 1, dy = 0;

    for (int i = 0; i < total; i++)
    {
        res[i] = matrix[y][x];
        matrix[y][x] = -101;

        int nextX = x + dx;
        int nextY = y + dy;

        if (!(0 <= nextX && nextX < cols && 0 <= nextY && nextY < rows) || matrix[nextY][nextX] == -101)
        {
            int temp = dx;
            dx = -dy;
            dy = temp;
        }

        x += dx;
        y += dy;
    }

    return res;
}
