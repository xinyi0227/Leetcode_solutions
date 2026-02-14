/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumDifference = function(nums, k) {
    nums.sort((a, b) => a - b);
    let ans = nums[k - 1] - nums[0];
    for (let i = 1; i + k <= nums.length; i++) {
        ans = Math.min(ans, nums[i + k - 1] - nums[i]);
    }
    return ans;
};