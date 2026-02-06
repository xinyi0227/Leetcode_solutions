#include <stdlib.h>
#include <stdbool.h>

int largestMagicSquare(int **grid, int gridSize, int *gridColSize)
{
    int r = gridSize;
    int c = gridColSize[0];

    int **rowSum = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        rowSum[i] = (int *)calloc(c + 1, sizeof(int));
        for (int j = 0; j < c; j++)
        {
            rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
        }
    }

    int **colSum = (int **)malloc(c * sizeof(int *));
    for (int j = 0; j < c; j++)
    {
        colSum[j] = (int *)calloc(r + 1, sizeof(int));
        for (int i = 0; i < r; i++)
        {
            colSum[j][i + 1] = colSum[j][i] + grid[i][j];
        }
    }

    int **diag = (int **)malloc((r + 1) * sizeof(int *));
    int **antidiag = (int **)malloc((r + 1) * sizeof(int *));
    for (int i = 0; i <= r; i++)
    {
        diag[i] = (int *)calloc(c + 1, sizeof(int));
        antidiag[i] = (int *)calloc(c + 1, sizeof(int));
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
            antidiag[i + 1][j] = antidiag[i][j + 1] + grid[i][j];
        }
    }

    int min_dim = r < c ? r : c;
    for (int k = min_dim; k > 1; k--)
    {
        for (int i = 0; i <= r - k; i++)
        {
            for (int j = 0; j <= c - k; j++)
            {
                int sum = diag[i + k][j + k] - diag[i][j];
                int antiSum = antidiag[i + k][j] - antidiag[i][j + k];

                if (sum != antiSum)
                    continue;

                bool match = true;
                for (int m = 0; m < k; m++)
                {
                    int rSum = rowSum[i + m][j + k] - rowSum[i + m][j];
                    int cSum = colSum[j + m][i + k] - colSum[j + m][i];
                    if (rSum != sum || cSum != sum)
                    {
                        match = false;
                        break;
                    }
                }

                if (match)
                    return k;
            }
        }
    }

    return 1;
}