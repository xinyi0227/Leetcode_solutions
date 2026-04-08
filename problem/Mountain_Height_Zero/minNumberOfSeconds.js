/**
 * @param {number} height
 * @param {number[]} times
 * @return {number}
 */
var minNumberOfSeconds = function(height, times) {
    let lo = 1n, hi = 10n ** 16n;

    while (lo < hi) {
        let mid = lo + (hi - lo) / 2n;
        let tot = 0n;
        for (let t of times) {
            tot += BigInt(Math.floor(Math.sqrt(Number(mid) / t * 2 + 0.25) - 0.5));
            if (tot >= BigInt(height)) break;
        }
        if (tot >= BigInt(height))
            hi = mid;
        else
            lo = mid + 1n;
    }

    return Number(lo);
};