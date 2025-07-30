/**
 * @param {number[]} nums
 * @return {number}
 */
function longestSubarray(nums) {
    if (!nums || nums.length === 0) return 0;
    
    let maxVal = nums[0];
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    
    let maxLen = 0;
    let currentLen = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === maxVal) {
            currentLen++;
        } else {
            maxLen = Math.max(maxLen, currentLen);
            currentLen = 0;
        }
    }

    return Math.max(maxLen, currentLen);
}
