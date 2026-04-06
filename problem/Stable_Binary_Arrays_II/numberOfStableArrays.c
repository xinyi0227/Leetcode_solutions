int dp[1005][1005][2];

int numberOfStableArrays(int zero, int one, int limit)
{
    int MOD = 1000000007;

    for (int i = 0; i <= zero; ++i)
    {
        for (int j = 0; j <= one; ++j)
        {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }

    int min_zero = zero < limit ? zero : limit;
    for (int i = 1; i <= min_zero; ++i)
        dp[i][0][0] = 1;

    int min_one = one < limit ? one : limit;
    for (int j = 1; j <= min_one; ++j)
        dp[0][j][1] = 1;

    for (int i = 1; i <= zero; ++i)
    {
        for (int j = 1; j <= one; ++j)
        {
            long long val0 = (long long)dp[i - 1][j][0] + dp[i - 1][j][1];
            if (i > limit)
            {
                val0 -= dp[i - limit - 1][j][1];
                if (val0 < 0)
                    val0 += MOD;
            }
            dp[i][j][0] = val0 % MOD;

            long long val1 = (long long)dp[i][j - 1][0] + dp[i][j - 1][1];
            if (j > limit)
            {
                val1 -= dp[i][j - limit - 1][0];
                if (val1 < 0)
                    val1 += MOD;
            }
            dp[i][j][1] = val1 % MOD;
        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}