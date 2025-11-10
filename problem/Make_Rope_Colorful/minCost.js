/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(colors, neededTime) {
    let n = colors.length, sum = 0;
    
    for (let i = 1; i < n; i++) {
        let maxi = 0;
        while (i < n && colors[i] === colors[i - 1]) {
            sum += neededTime[i - 1];
            maxi = Math.max(maxi, neededTime[i - 1]);
            ++i;
        }
        sum += neededTime[i - 1];
        maxi = Math.max(maxi, neededTime[i - 1]);
        if (maxi !== 0) sum -= maxi;
    }
    return sum;
};