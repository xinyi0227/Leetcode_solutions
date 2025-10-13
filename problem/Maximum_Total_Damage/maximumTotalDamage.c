#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

static int findPrev(int *keys, int n, int x)
{
    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int m = l + ((r - l) >> 1);
        if (keys[m] <= x)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}

long long maximumTotalDamage(int *power, int powerSize)
{
    if (powerSize <= 0)
        return 0;
    qsort(power, powerSize, sizeof(int), cmp_int);

    int *keys = (int *)malloc(sizeof(int) * powerSize);
    long long *cnt = (long long *)malloc(sizeof(long long) * powerSize);
    int n = 0;
    for (int i = 0; i < powerSize;)
    {
        int v = power[i];
        long long c = 0;
        while (i < powerSize && power[i] == v)
        {
            ++c;
            ++i;
        }
        keys[n] = v;
        cnt[n] = c;
        ++n;
    }

    long long *dp = (long long *)malloc(sizeof(long long) * n);
    dp[0] = cnt[0] * (long long)keys[0];
    for (int i = 1; i < n; ++i)
    {
        long long take = cnt[i] * (long long)keys[i];
        int prev = findPrev(keys, i, keys[i] - 3);
        if (prev >= 0)
            take += dp[prev];
        dp[i] = dp[i - 1] > take ? dp[i - 1] : take;
    }
    long long ans = dp[n - 1];
    free(dp);
    free(cnt);
    free(keys);
    return ans;
}