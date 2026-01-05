/**
 * @param {number[]} prices
 * @return {number}
 */
var getDescentPeriods = function(prices) {
    let ans = 1;
    let count = 1;
    for (let i = 0; i < prices.length - 1; i++) {
        if (prices[i] === prices[i + 1] + 1) {
            count++;
        } else {
            count = 1;
        }
        ans += count;
    }
    return ans;
};