/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxOperations = function(nums, k) {
    let n = nums.length;
    let i = 0;
    let j = n - 1;
    let count = 0;
    nums.sort((a, b) => a - b);
    while (i < j) {
        let sum = nums[i] + nums[j];
        if (sum === k) {
            count++;
            i++;
            j--;
        }
        if (sum < k) {
            i++;
        }
        if (sum > k) {
            j--;
        }
    }
    return count;
};
