int minScoreTriangulation(int *v, int vSize)
{
    int n = vSize;
    int **dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        dp[i] = (int *)calloc(n, sizeof(int));
    }

    for (int l = 3; l <= n; l++)
    {
        for (int i = 0; i + l - 1 < n; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                int cost = dp[i][k] + dp[k][j] + v[i] * v[j] * v[k];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    int result = dp[0][n - 1];

    for (int i = 0; i < n; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return result;
}
