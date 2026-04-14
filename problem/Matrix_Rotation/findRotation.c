bool isEqual(int **mat, int **target, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != target[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void rotate(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        int *tempRow = mat[i];
        mat[i] = mat[n - 1 - i];
        mat[n - 1 - i] = tempRow;
    }
}

bool findRotation(int **mat, int matSize, int *matColSize, int **target, int targetSize, int *targetColSize)
{
    for (int k = 0; k < 4; k++)
    {
        if (isEqual(mat, target, matSize))
        {
            return true;
        }
        rotate(mat, matSize);
    }

    return false;
}