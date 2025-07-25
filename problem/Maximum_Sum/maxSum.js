/**
 * @param {number[]} nums
 * @return {number}
 */
function maxSum(nums) {
    let allNegative = true;
    let maxValue = -Infinity;
    for (const n of nums) {
        if (n >= 0) allNegative = false;
        if (n > maxValue) maxValue = n;
    }
    if (allNegative) return maxValue;

    const seen = new Array(101).fill(false);
    for (const n of nums) {
        if (n >= 0 && n < 101) {
            seen[n] = true;
        }
    }

    let sum = 0;
    for (let i = 1; i <= 100; i++) {
        if (seen[i]) sum += i;
    }
    return sum;
}