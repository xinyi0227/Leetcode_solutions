/**
 * @param {number[]} A
 * @param {number} k
 * @return {number}
 */
var maximumProfit = function(A, k) {
    let res = new Array(k + 1).fill(0);
    let bought = new Array(k).fill(-1e9);
    let sold = new Array(k).fill(0);

    for (let a of A) {
        for (let j = k; j >= 1; --j) {
            res[j] = Math.max(res[j], bought[j - 1] + a, sold[j - 1] - a);
            bought[j - 1] = Math.max(bought[j - 1], res[j - 1] - a);
            sold[j - 1] = Math.max(sold[j - 1], res[j - 1] + a);
        }
    }
    return Math.max(...res);
};