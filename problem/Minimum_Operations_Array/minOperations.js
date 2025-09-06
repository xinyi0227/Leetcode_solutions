/**
 * @param {number[][]} queries
 * @return {number}
 */
var minOperations = function(queries) {
    const pow4 = [1n];
    while (pow4[pow4.length - 1] <= 1000000000n) {
        pow4.push(pow4[pow4.length - 1] * 4n);
    }

    const prefix = [0n];
    for (let i = 0; i < pow4.length - 1; i++) {
        prefix.push(prefix[prefix.length - 1] + BigInt(i + 1) * 3n * pow4[i]);
    }

    function F(n) {
        if (n <= 0n) return 0n;
        let idx = upperBound(pow4, n) - 1;
        return prefix[idx] + BigInt(idx + 1) * (n - pow4[idx] + 1n);
    }

    function upperBound(arr, x) {
        let l = 0, r = arr.length;
        while (l < r) {
        let m = (l + r) >> 1;
        if (arr[m] <= x) l = m + 1;
        else r = m;
        }
        return l;
    }

    let res = 0n;
    for (let [l, r] of queries) {
        let s = F(BigInt(r)) - F(BigInt(l - 1));
        res += (s + 1n) / 2n;
    }
    return Number(res);
};