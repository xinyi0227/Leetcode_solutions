long long modPow(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int *productQueries(int n, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    const int MOD = 1000000007;

    int p[32];
    p[0] = 0;
    int pSize = 1;

    for (int i = 0; i < 31; i++)
    {
        if (n >> i & 1)
        {
            p[pSize] = p[pSize - 1] + i;
            pSize++;
        }
    }

    int *res = (int *)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++)
    {
        res[i] = (int)modPow(2, p[queries[i][1] + 1] - p[queries[i][0]], MOD);
    }

    return res;
}
