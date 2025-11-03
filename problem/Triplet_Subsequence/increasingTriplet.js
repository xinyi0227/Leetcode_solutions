/**
 * @param {number[]} nums
 * @return {boolean}
 */
var increasingTriplet = function(nums) {
    let i = Infinity, j = Infinity;
    for (let num of nums) {
        if (num <= i) i = num;
        else if (num <= j) j = num;
        else return true;
    }
    return false;
};
