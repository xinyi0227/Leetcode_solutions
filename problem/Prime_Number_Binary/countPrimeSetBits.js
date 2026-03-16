/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var countPrimeSetBits = function(left, right) {
    const primes = new Set([2, 3, 5, 7, 11, 13, 17, 19]);
    let count = 0;
    for (let i = left; i <= right; i++) {
        let setBits = i.toString(2).split('0').join('').length;
        if (primes.has(setBits)) {
            count++;
        }
    }
    return count;
};