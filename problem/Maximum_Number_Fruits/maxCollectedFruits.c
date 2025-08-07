int max(int a, int b) { return a > b ? a : b; }
int max3(int a, int b, int c) { return max(max(a, b), c); }

int maxCollectedFruits(int **fruits, int fruitsSize, int *fruitsColSize)
{
    int n = fruitsSize, total = 0;
    for (int i = 0; i < n; ++i)
        total += fruits[i][i];

    int *rightPath = (int *)calloc(3, sizeof(int));
    int *bottomPath = (int *)calloc(3, sizeof(int));
    rightPath[0] = fruits[0][n - 1];
    bottomPath[0] = fruits[n - 1][0];

    int window = 2;

    for (int step = 1; step < n - 1; ++step)
    {
        int *newRight = (int *)calloc(window + 2, sizeof(int));
        int *newBottom = (int *)calloc(window + 2, sizeof(int));
        for (int dist = 0; dist < window; ++dist)
        {
            int l = dist - 1 >= 0 ? rightPath[dist - 1] : 0;
            int m = rightPath[dist];
            int r = dist + 1 < step + 2 ? rightPath[dist + 1] : 0;
            newRight[dist] = max3(l, m, r) + fruits[step][n - 1 - dist];

            l = dist - 1 >= 0 ? bottomPath[dist - 1] : 0;
            m = bottomPath[dist];
            r = dist + 1 < step + 2 ? bottomPath[dist + 1] : 0;
            newBottom[dist] = max3(l, m, r) + fruits[n - 1 - dist][step];
        }
        free(rightPath);
        free(bottomPath);
        rightPath = newRight;
        bottomPath = newBottom;

        if (window - n + 4 + step <= 1)
            window++;
        else if (window - n + 3 + step > 1)
            window--;
    }
    int result = total + rightPath[0] + bottomPath[0];
    free(rightPath);
    free(bottomPath);
    return result;
}
