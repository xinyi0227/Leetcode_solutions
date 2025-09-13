/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function(n) {
    const a = [];
    if (n % 2 !== 0) a.push(0);
    for (let i = 1; i <= Math.floor(n / 2); i++) {
        a.push(i, -i);
    }
    return a;
};
