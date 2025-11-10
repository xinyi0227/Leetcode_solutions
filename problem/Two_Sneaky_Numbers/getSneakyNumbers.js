/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function(nums) {
    const n = nums.length;
    const seen = new Array(n).fill(false);
    const res = [];
    for (const x of nums) {
        if (x < n && seen[x]) {
            res.push(x);
        } else if (x < n) {
            seen[x] = true;
        }
    }
    return res;
};