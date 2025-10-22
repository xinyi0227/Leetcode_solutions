/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxDistinctElements = function(nums, k) {
    nums.sort((a, b) => a - b);
    let ans = 0, prev = -1e9;
    for (let i = 0; i < nums.length; i++) {
        let l = Math.max(nums[i] - k, prev + 1);
        if (l <= nums[i] + k) {
            prev = l;
            ans++;
        }
    }
    return ans;
};