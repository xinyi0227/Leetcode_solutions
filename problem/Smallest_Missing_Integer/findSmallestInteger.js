/**
 * @param {number[]} nums
 * @param {number} value
 * @return {number}
 */
var findSmallestInteger = function(nums, v) {
    let n = nums.length, res = 0;
    let rem = new Array(v).fill(0);
    for (let i = 0; i < n; i++) {
        let x = ((nums[i] % v) + v) % v;
        rem[x]++;
    }
    while (rem[res % v]--) res++;
    return res;
};