/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function(nums) {
  const seen = new Set();
  let left = 0, currentSum = 0, maxSum = 0;

  for (let right = 0; right < nums.length; right++) {
    while (seen.has(nums[right])) {
      seen.delete(nums[left]);
      currentSum -= nums[left];
      left++;
    }
    seen.add(nums[right]);
    currentSum += nums[right];
    maxSum = Math.max(maxSum, currentSum);
  }

  return maxSum;
};