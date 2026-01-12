long long maxProfit(int *prices, int pricesSize, int *strat, int stratSize, int k)
{
    int n = pricesSize;
    int h = k / 2;

    long long *sp = (long long *)malloc(sizeof(long long) * n);
    long long base = 0;
    for (int i = 0; i < n; i++)
    {
        sp[i] = (long long)strat[i] * (long long)prices[i];
        base += sp[i];
    }

    if (n == k)
    {
        long long win_orig = base;
        long long win_mod = 0;
        for (int i = h; i < n; i++)
            win_mod += (long long)prices[i];
        long long change = win_mod - win_orig;
        long long ans = base + (change > 0 ? change : 0);
        free(sp);
        return ans;
    }

    long long win_orig = 0;
    for (int i = 0; i < k; i++)
        win_orig += sp[i];

    long long win_mod = 0;
    for (int i = h; i < k; i++)
        win_mod += (long long)prices[i];

    long long max_ch = win_mod - win_orig;

    for (int i = 1; i <= n - k; i++)
    {
        win_orig += sp[i + k - 1] - sp[i - 1];
        win_mod += (long long)prices[i + k - 1] - (long long)prices[i - 1 + h];
        long long diff = win_mod - win_orig;
        if (diff > max_ch)
            max_ch = diff;
    }

    long long ans = base + (max_ch > 0 ? max_ch : 0);
    free(sp);
    return ans;
}