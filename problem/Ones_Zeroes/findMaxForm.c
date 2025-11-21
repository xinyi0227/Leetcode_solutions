int findMaxForm(char **strs, int strsSize, int m, int n)
{
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
    {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }

    for (int s = 0; s < strsSize; s++)
    {
        int zeros = 0, ones = 0;
        for (int k = 0; strs[s][k]; k++)
        {
            if (strs[s][k] == '0')
                zeros++;
            else
                ones++;
        }
        for (int i = m; i >= zeros; i--)
        {
            for (int j = n; j >= ones; j--)
            {
                int val = dp[i - zeros][j - ones] + 1;
                if (val > dp[i][j])
                    dp[i][j] = val;
            }
        }
    }

    int result = dp[m][n];
    for (int i = 0; i <= m; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return result;
}