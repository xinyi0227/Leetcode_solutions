/**
 * @param {number} zero
 * @param {number} one
 * @param {number} limit
 * @return {number}
 */
var numberOfStableArrays = function(zero, one, limit) {
    const MOD = 1000000007n;
    const maxN = zero + one;
    const fact = new BigInt64Array(maxN + 1);
    const invFact = new BigInt64Array(maxN + 1);

    const power = (base, exp) => {
        let res = 1n;
        base %= MOD;
        while (exp > 0n) {
            if (exp % 2n === 1n) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2n;
        }
        return res;
    };

    fact[0] = 1n;
    for (let i = 1; i <= maxN; i++) fact[i] = (fact[i - 1] * BigInt(i)) % MOD;
    invFact[maxN] = power(fact[maxN], MOD - 2n);
    for (let i = maxN - 1; i >= 0; i--) invFact[i] = (invFact[i + 1] * BigInt(i + 1)) % MOD;

    const nCr = (n, r) => {
        if (r < 0 || r > n) return 0n;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    };

    const F = (N, K, L) => {
        if (K <= 0 || K > N) return 0n;
        let ans = 0n;
        let maxJ = Math.floor((N - K) / L);
        for (let j = 0; j <= maxJ; j++) {
            let term = (nCr(K, j) * nCr(N - j * L - 1, K - 1)) % MOD;
            if (j & 1) ans = (ans - term + MOD) % MOD;
            else ans = (ans + term) % MOD;
        }
        return ans;
    };

    const maxK = Math.min(zero, one + 1);
    const fOne = new BigInt64Array(maxK + 2);
    for (let k = 1; k <= maxK + 1; k++) fOne[k] = F(one, k, limit);

    let ans = 0n;
    for (let k = 1; k <= maxK; k++) {
        let fz = F(zero, k, limit);
        if (fz === 0n) continue;
        let fo = (fOne[k - 1] + 2n * fOne[k] + fOne[k + 1]) % MOD;
        ans = (ans + (fz * fo)) % MOD;
    }

    return Number(ans);
};