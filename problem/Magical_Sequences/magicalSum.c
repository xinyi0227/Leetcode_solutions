#include <stdlib.h>
#include <string.h>

int magicalSum(int m, int k, int *nums, int numsSize)
{
    const int MOD = 1000000007;
    int n = numsSize;
    long long *C = (long long *)calloc((m + 1) * (m + 1), sizeof(long long));
    for (int i = 0; i <= m; i++)
    {
        C[i * (m + 1) + 0] = 1;
        C[i * (m + 1) + i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i * (m + 1) + j] = (C[(i - 1) * (m + 1) + (j - 1)] + C[(i - 1) * (m + 1) + j]) % MOD;
        }
    }
    long long *powA = (long long *)malloc((long long)n * (m + 1) * sizeof(long long));
    for (int i = 0; i < n; i++)
    {
        long long a = nums[i] % MOD;
        powA[(long long)i * (m + 1) + 0] = 1;
        for (int t = 1; t <= m; t++)
        {
            powA[(long long)i * (m + 1) + t] = (powA[(long long)i * (m + 1) + t - 1] * a) % MOD;
        }
    }
    int M = m;
    int S = M + 1;
    long long total = (long long)S * S * S;
    long long *cur = (long long *)calloc(total, sizeof(long long));
    long long *nxt = (long long *)calloc(total, sizeof(long long));
#define IDX(r, c, o) ((((long long)(r)) * S + (c)) * S + (o))
    cur[IDX(M, 0, 0)] = 1;
    for (int i = 0; i < n; i++)
    {
        memset(nxt, 0, total * sizeof(long long));
        for (int r = 0; r <= M; r++)
        {
            for (int carry = 0; carry <= M; carry++)
            {
                long long base = ((long long)r) * S + carry;
                base *= S;
                for (int ones = 0; ones <= M; ones++)
                {
                    long long val = cur[base + ones];
                    if (!val)
                        continue;
                    for (int t = 0; t <= r; t++)
                    {
                        int newr = r - t;
                        int sum = carry + t;
                        int bit = sum & 1;
                        int newones = ones + bit;
                        if (newones > M)
                            continue;
                        int newcarry = sum >> 1;
                        long long mult = (C[r * (m + 1) + t] * powA[(long long)i * (m + 1) + t]) % MOD;
                        long long add = (val * mult) % MOD;
                        long long j = IDX(newr, newcarry, newones);
                        long long v = nxt[j] + add;
                        if (v >= MOD)
                            v -= MOD;
                        nxt[j] = v;
                    }
                }
            }
        }
        long long *tmp = cur;
        cur = nxt;
        nxt = tmp;
    }
    long long ans = 0;
    for (int carry = 0; carry <= M; carry++)
    {
        for (int ones = 0; ones <= M; ones++)
        {
            long long val = cur[IDX(0, carry, ones)];
            if (!val)
                continue;
            int extra = __builtin_popcount((unsigned)carry);
            if (ones + extra == k)
            {
                ans += val;
                if (ans >= MOD)
                    ans -= MOD;
            }
        }
    }
    free(C);
    free(powA);
    free(cur);
    free(nxt);
    return (int)(ans % MOD);
}