int binarySearch(long long *pow4, int len, long long n)
{
    int left = 0, right = len - 1, ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (pow4[mid] <= n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

long long minOperations(int **queries, int queriesSize, int *queriesColSize)
{
    long long pow4[30];
    pow4[0] = 1;
    int i, count = 1;
    while (pow4[count - 1] <= 1000000000LL)
    {
        pow4[count] = pow4[count - 1] * 4;
        count++;
    }
    long long prefix[31];
    prefix[0] = 0;
    for (i = 0; i < count; i++)
    {
        prefix[i + 1] = prefix[i] + (i + 1) * 3 * pow4[i];
    }
    long long F(long long n)
    {
        if (n <= 0)
            return 0LL;
        int k = binarySearch(pow4, count, n);
        return prefix[k] + (k + 1) * (n - pow4[k] + 1);
    };
    long long res = 0;
    for (i = 0; i < queriesSize; i++)
    {
        int l = queries[i][0], r = queries[i][1];
        long long s = F(r) - F(l - 1);
        res += (s + 1) / 2;
    }
    return res;
}
