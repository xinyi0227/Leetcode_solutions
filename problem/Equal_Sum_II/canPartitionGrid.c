#include <stdlib.h>
#include <stdbool.h>

bool check(int *freq, int **grid, int r1, int r2, int c1, int c2, long long diff)
{
    int rows = r2 - r1 + 1;
    int cols = c2 - c1 + 1;

    if (rows * cols == 1)
        return false;

    if (rows == 1)
    {
        return (grid[r1][c1] == diff || grid[r1][c2] == diff);
    }

    if (cols == 1)
    {
        return (grid[r1][c1] == diff || grid[r2][c1] == diff);
    }

    return freq[diff] > 0;
}

bool canPartitionGrid(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    long long total = 0;

    int *bottomFreq = (int *)calloc(100001, sizeof(int));
    int *topFreq = (int *)calloc(100001, sizeof(int));
    int *rightFreq = (int *)calloc(100001, sizeof(int));
    int *leftFreq = (int *)calloc(100001, sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = grid[i][j];
            total += x;
            bottomFreq[x]++;
            rightFreq[x]++;
        }
    }

    long long sumTop = 0;

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = grid[i][j];
            sumTop += val;
            topFreq[val]++;
            bottomFreq[val]--;
        }

        long long sumBottom = total - sumTop;

        if (sumTop == sumBottom)
        {
            free(bottomFreq);
            free(topFreq);
            free(rightFreq);
            free(leftFreq);
            return true;
        }

        long long diff = llabs(sumTop - sumBottom);

        if (diff <= 100000)
        {
            if (sumTop > sumBottom)
            {
                if (check(topFreq, grid, 0, i, 0, n - 1, diff))
                {
                    free(bottomFreq);
                    free(topFreq);
                    free(rightFreq);
                    free(leftFreq);
                    return true;
                }
            }
            else
            {
                if (check(bottomFreq, grid, i + 1, m - 1, 0, n - 1, diff))
                {
                    free(bottomFreq);
                    free(topFreq);
                    free(rightFreq);
                    free(leftFreq);
                    return true;
                }
            }
        }
    }

    long long sumLeft = 0;

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < m; i++)
        {
            int val = grid[i][j];
            sumLeft += val;
            leftFreq[val]++;
            rightFreq[val]--;
        }

        long long sumRight = total - sumLeft;

        if (sumLeft == sumRight)
        {
            free(bottomFreq);
            free(topFreq);
            free(rightFreq);
            free(leftFreq);
            return true;
        }

        long long diff = llabs(sumLeft - sumRight);

        if (diff <= 100000)
        {
            if (sumLeft > sumRight)
            {
                if (check(leftFreq, grid, 0, m - 1, 0, j, diff))
                {
                    free(bottomFreq);
                    free(topFreq);
                    free(rightFreq);
                    free(leftFreq);
                    return true;
                }
            }
            else
            {
                if (check(rightFreq, grid, 0, m - 1, j + 1, n - 1, diff))
                {
                    free(bottomFreq);
                    free(topFreq);
                    free(rightFreq);
                    free(leftFreq);
                    return true;
                }
            }
        }
    }

    free(bottomFreq);
    free(topFreq);
    free(rightFreq);
    free(leftFreq);
    return false;
}