/**
 * @param {number[]} nums
 * @return {number}
 */
var countPartitions = function(nums) {
    let totalSum = 0;
    for (let i = 0; i < nums.length; i++) totalSum += nums[i];
    let leftSum = 0, count = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        leftSum += nums[i];
        let rightSum = totalSum - leftSum;
        if ((leftSum % 2) === (rightSum % 2)) count++;
    }
    return count;
};
