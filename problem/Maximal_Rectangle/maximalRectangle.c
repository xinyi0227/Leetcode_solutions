#include <math.h>

int area(int *heights, int n)
{
    int *st = (int *)malloc((n + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        int h = (i == n) ? 0 : heights[i];
        while (top != -1 && h < heights[st[top]])
        {
            int height = heights[st[top--]];
            int width = (top == -1) ? i : i - st[top] - 1;
            int currentArea = height * width;
            if (currentArea > maxArea)
                maxArea = currentArea;
        }
        st[++top] = i;
    }
    free(st);
    return maxArea;
}

int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize)
{
    if (matrixSize == 0)
        return 0;
    int n = matrixColSize[0];
    int *hist = (int *)calloc(n, sizeof(int));
    int ans = 0;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
            {
                hist[j]++;
            }
            else
            {
                hist[j] = 0;
            }
        }
        int currentMax = area(hist, n);
        if (currentMax > ans)
            ans = currentMax;
    }
    free(hist);
    return ans;
}