/**
 * @param {number} n
 * @return {number}
 */
const binaryGap = n => {
    n /= n & -n;
    if (n === 1) return 0;

    let max = 0, gap = 0;

    while (n) {
        if (n & 1) {
            max = Math.max(max, gap);
            gap = 0;
        } else
            gap++;
        n >>= 1;
    }

    return max + 1;
};