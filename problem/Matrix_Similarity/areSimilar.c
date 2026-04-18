#include <stdbool.h>

bool areSimilar(int **mat, int matSize, int *matColSize, int k)
{
    int m = matSize;
    int n = matColSize[0];
    k %= n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 2 == 0)
            {
                if (mat[i][j] != mat[i][(j + k) % n])
                {
                    return false;
                }
            }
            else
            {
                if (mat[i][j] != mat[i][(j - k + n) % n])
                {
                    return false;
                }
            }
        }
    }
    return true;
}