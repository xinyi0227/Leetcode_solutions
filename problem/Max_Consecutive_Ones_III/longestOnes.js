/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function(nums, k) {
    let l = 0, r = 0, zeroes = 0, maxlen = 0;
    
    while (r < nums.length) {
        if (nums[r] === 0) zeroes++;
        
        while (zeroes > k) {
            if (nums[l] === 0) zeroes--;
            l++;
        }
        
        maxlen = Math.max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
};