double f(int a, int b, double **dp)
{
    if (a <= 0 && b > 0)
        return 1.0;
    if (a == 0 && b == 0)
        return 0.5;
    if (a > 0 && b <= 0)
        return 0.0;
    if (a <= 0 && b <= 0)
        return 0.5;
    if (dp[a][b] != -1)
        return dp[a][b];
    double x = 0.25 * f(a - 100, b, dp);
    double y = 0.25 * f(a - 75, b - 25, dp);
    double z = 0.25 * f(a - 50, b - 50, dp);
    double w = 0.25 * f(a - 25, b - 75, dp);
    return dp[a][b] = x + y + z + w;
}

double soupServings(int n)
{
    if (n > 4800)
        return 1.0;
    int size = n + 1;
    double **dp = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; ++i)
    {
        dp[i] = (double *)malloc(size * sizeof(double));
        for (int j = 0; j < size; ++j)
            dp[i][j] = -1;
    }
    double res = f(n, n, dp);
    for (int i = 0; i < size; ++i)
        free(dp[i]);
    free(dp);
    return res;
}
