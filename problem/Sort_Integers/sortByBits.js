/**
 * @param {number[]} arr
 * @return {number[]}
 */
var sortByBits = function(arr) {
    return arr.sort((a, b) => {
        const countA = a.toString(2).split('1').length - 1;
        const countB = b.toString(2).split('1').length - 1;
        return countA - countB || a - b;
    });
};