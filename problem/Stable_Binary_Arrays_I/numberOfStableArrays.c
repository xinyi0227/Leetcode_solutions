#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long nCr(int n, int r, long long *fact, long long *invFact)
{
    if (r < 0 || r > n)
        return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

long long F(int N, int K, int L, long long *fact, long long *invFact)
{
    if (K <= 0 || K > N)
        return 0;
    long long ans = 0;
    int maxJ = (N - K) / L;
    for (int j = 0; j <= maxJ; j++)
    {
        long long term = (nCr(K, j, fact, invFact) * nCr(N - j * L - 1, K - 1, fact, invFact)) % MOD;
        if (j & 1)
            ans = (ans - term + MOD) % MOD;
        else
            ans = (ans + term) % MOD;
    }
    return ans;
}

int numberOfStableArrays(int zero, int one, int limit)
{
    int maxN = zero + one;
    long long *fact = (long long *)malloc((maxN + 1) * sizeof(long long));
    long long *invFact = (long long *)malloc((maxN + 1) * sizeof(long long));

    fact[0] = 1;
    for (int i = 1; i <= maxN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    invFact[maxN] = power(fact[maxN], MOD - 2);
    for (int i = maxN - 1; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;

    int maxK = (zero < one + 1) ? zero : one + 1;
    long long *fOne = (long long *)calloc((maxK + 2), sizeof(long long));
    for (int k = 1; k <= maxK + 1; k++)
        fOne[k] = F(one, k, limit, fact, invFact);

    long long ans = 0;
    for (int k = 1; k <= maxK; k++)
    {
        long long fz = F(zero, k, limit, fact, invFact);
        if (fz == 0)
            continue;
        long long fo = (fOne[k - 1] + 2 * fOne[k] + fOne[k + 1]) % MOD;
        ans = (ans + (fz * fo)) % MOD;
    }

    free(fact);
    free(invFact);
    free(fOne);
    return (int)ans;
}