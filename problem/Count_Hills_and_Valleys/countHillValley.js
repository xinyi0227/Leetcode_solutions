/**
 * @param {number[]} nums
 * @return {number}
 */
function countHillValley(nums) {
    let cnt = 0;
    let j = 0;
    const n = nums.length;
    
    for (let i = 1; i < n - 1; i++) {
        if ((nums[j] < nums[i] && nums[i] > nums[i + 1]) ||
            (nums[j] > nums[i] && nums[i] < nums[i + 1])) {
            cnt++;
            j = i;
        }
    }
    
    return cnt;
}
