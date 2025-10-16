/**
 * @param {number} n
 * @param {number[][]} conflictingPairs
 * @return {number}
 */
var maxSubarrays = function(n, conflictingPairs) {
    let conflicts = Array.from({length: n + 2}, () => []);
    for (let pair of conflictingPairs) {
        let a = pair[0];
        let b = pair[1];
        if (a < b) {
            conflicts[b].push(a);
        } else {
            conflicts[a].push(b);
        }
    }
    let maxLeft = 0;
    let secondMaxLeft = 0;
    let gains = new Array(n + 2).fill(0);
    let validSubarrays = 0;
    for (let right = 1; right <= n; right++) {
        for (let left of conflicts[right]) {
            if (left > maxLeft) {
                secondMaxLeft = maxLeft;
                maxLeft = left;
            } else if (left > secondMaxLeft) {
                secondMaxLeft = left;
            }
        }
        validSubarrays += right - maxLeft;
        gains[maxLeft] += maxLeft - secondMaxLeft;
    }
    let maxGain = Math.max(...gains);
    return validSubarrays + maxGain;
};