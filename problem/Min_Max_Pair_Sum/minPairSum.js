/**
 * @param {number[]} nums
 * @return {number}
 */
var minPairSum = function(nums) {
    nums.sort((a, b) => a - b);
    let res = 0;
    let n = nums.length;
    
    for (let i = 0; i < n >> 1; i++) {
        res = Math.max(res, nums[i] + nums[n - 1 - i]);
    }
    
    return res;
};