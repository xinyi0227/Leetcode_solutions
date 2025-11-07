/**
 * @param {number[]} target
 * @return {number}
 */
var minNumberOperations = function(target) {
    let sum = target[0];
    for (let i = 1; i < target.length; i++) {
        let diff = target[i] - target[i - 1];
        if (diff > 0) {
            sum += diff;
        }
    }
    return sum;
};