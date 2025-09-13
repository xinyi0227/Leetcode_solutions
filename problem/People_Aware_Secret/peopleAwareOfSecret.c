int peopleAwareOfSecret(int n, int delay, int forget)
{
    const long long MOD = 1000000007LL;
    long long *dp = (long long *)calloc(n + 1, sizeof(long long));
    dp[1] = 1;
    long long share = 0;

    for (int t = 2; t <= n; ++t)
    {
        if (t - delay > 0)
        {
            share = (share + dp[t - delay]) % MOD;
        }
        if (t - forget > 0)
        {
            share = (share - dp[t - forget] + MOD) % MOD;
        }
        dp[t] = share;
    }

    long long know = 0;
    int start = n - forget + 1;
    if (start < 1)
        start = 1;
    for (int i = start; i <= n; ++i)
    {
        know = (know + dp[i]) % MOD;
    }

    free(dp);
    return (int)know;
}
