#include <stdlib.h>
#include <string.h>

long long max2(long long a, long long b)
{
    return a > b ? a : b;
}

long long max3(long long a, long long b, long long c)
{
    return max2(a, max2(b, c));
}

long long maximumProfit(int *A, int ASize, int k)
{
    long long *res = (long long *)calloc(k + 1, sizeof(long long));
    long long *bought = (long long *)malloc(k * sizeof(long long));
    long long *sold = (long long *)calloc(k, sizeof(long long));

    for (int i = 0; i < k; ++i)
    {
        bought[i] = -1000000000LL;
    }

    for (int i = 0; i < ASize; ++i)
    {
        int a = A[i];
        for (int j = k; j >= 1; --j)
        {
            res[j] = max3(res[j], bought[j - 1] + a, sold[j - 1] - a);
            bought[j - 1] = max2(bought[j - 1], res[j - 1] - a);
            sold[j - 1] = max2(sold[j - 1], res[j - 1] + a);
        }
    }

    long long maxVal = res[0];
    for (int i = 1; i <= k; ++i)
    {
        if (res[i] > maxVal)
            maxVal = res[i];
    }

    free(res);
    free(bought);
    free(sold);
    return maxVal;
}