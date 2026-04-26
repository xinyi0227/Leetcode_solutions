var xorAfterQueries = function(nums, queries) {
    const n = nums.length;
    const MOD = 1000000007n;
    const limit = Math.floor(Math.sqrt(n)) >> 1 || 1;
    
    let numsBig = new BigUint64Array(n);
    for (let i = 0; i < n; i++) numsBig[i] = BigInt(nums[i]);

    const lightK = Array.from({ length: limit }, () => []);
    const heavyQueries = [];

    for (let i = 0; i < queries.length; i++) {
        const [l, r, k, v] = queries[i];
        if (k >= limit) {
            heavyQueries.push(l, r, k, BigInt(v));
        } else {
            lightK[k].push(l, r, BigInt(v));
        }
    }

    for (let i = 0; i < heavyQueries.length; i += 4) {
        const l = heavyQueries[i];
        const r = heavyQueries[i + 1];
        const k = heavyQueries[i + 2];
        const v = heavyQueries[i + 3];
        for (let j = l; j <= r; j += k) {
            numsBig[j] = (numsBig[j] * v) % MOD;
        }
    }

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

    const modInverse = (v) => power(v, MOD - 2n);

    const diff = new BigUint64Array(n + limit + 1);

    for (let k = 1; k < limit; k++) {
        const qs = lightK[k];
        if (qs.length === 0) continue;

        diff.fill(1n);
        
        for (let i = 0; i < qs.length; i += 3) {
            const l = qs[i];
            const r = qs[i + 1];
            const v = qs[i + 2];
            
            diff[l] = (diff[l] * v) % MOD;
            const steps = Math.floor((r - l) / k);
            const nxt = l + (steps + 1) * k;
            if (nxt < n + k) {
                const invV = modInverse(v);
                diff[nxt] = (diff[nxt] * invV) % MOD;
            }
        }

        for (let i = 0; i < n; i++) {
            if (i >= k) {
                diff[i] = (diff[i] * diff[i - k]) % MOD;
            }
            numsBig[i] = (numsBig[i] * diff[i]) % MOD;
        }
    }

    let ans = 0;
    for (let i = 0; i < n; i++) {
        ans ^= Number(numsBig[i]);
    }

    return ans;
};