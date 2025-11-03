/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(nums, k) {
    let windowSum = 0;
    let maxSum = 0;
    
    if (nums.length < k) {
        return -1;
    }
    
    for (let i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    maxSum = windowSum;
    
    for (let i = k; i < nums.length; i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = Math.max(maxSum, windowSum);
    }
    
    return maxSum / k;
};
