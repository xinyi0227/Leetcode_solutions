#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long power(long long base, long long exp)
{
    long long res = 1;
    long long mod = 1000000007;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n)
{
    return power(n, 1000000007 - 2);
}

int xorAfterQueries(int *nums, int numsSize, int **queries, int queriesSize, int *queriesColSize)
{
    long long mod = 1000000007;
    int limit = (int)sqrt(numsSize);
    long long *numsLL = malloc(numsSize * sizeof(long long));
    for (int i = 0; i < numsSize; i++)
        numsLL[i] = nums[i];

    int *processed = calloc(queriesSize, sizeof(int));

    for (int i = 0; i < queriesSize; i++)
    {
        int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
        if (k >= limit)
        {
            for (int j = l; j <= r; j += k)
            {
                numsLL[j] = (numsLL[j] * v) % mod;
            }
            processed[i] = 1;
        }
    }

    for (int k = 1; k < limit; k++)
    {
        int found = 0;
        for (int i = 0; i < queriesSize; i++)
        {
            if (!processed[i] && queries[i][2] == k)
            {
                found = 1;
                break;
            }
        }
        if (!found)
            continue;

        long long *diff = malloc((numsSize + k + 1) * sizeof(long long));
        for (int i = 0; i < numsSize + k + 1; i++)
            diff[i] = 1;

        for (int i = 0; i < queriesSize; i++)
        {
            if (!processed[i] && queries[i][2] == k)
            {
                int l = queries[i][0], r = queries[i][1], v = queries[i][3];
                diff[l] = (diff[l] * v) % mod;
                int steps = (r - l) / k;
                int nxt = l + (steps + 1) * k;
                if (nxt < numsSize + k)
                {
                    diff[nxt] = (diff[nxt] * modInverse(v)) % mod;
                }
            }
        }

        for (int i = 0; i < numsSize; i++)
        {
            if (i >= k)
                diff[i] = (diff[i] * diff[i - k]) % mod;
            numsLL[i] = (numsLL[i] * diff[i]) % mod;
        }
        free(diff);
    }

    int ans = 0;
    for (int i = 0; i < numsSize; i++)
        ans ^= (int)numsLL[i];

    free(numsLL);
    free(processed);
    return ans;
}