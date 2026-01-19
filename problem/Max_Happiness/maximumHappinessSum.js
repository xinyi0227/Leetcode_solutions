/**
 * @param {number[]} happiness
 * @param {number} k
 * @return {number}
 */
var maximumHappinessSum = function(happiness, k) {
    happiness.sort((a, b) => a - b);
    
    let sum = 0;
    const n = happiness.length;
    
    for (let i = 0; i < k; i++) {
        let x = Math.max(0, happiness[n - 1 - i] - i);
        sum += x;
    }
    
    return sum;
};