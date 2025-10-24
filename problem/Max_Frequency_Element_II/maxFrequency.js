/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} numOperations
 * @return {number}
 */
var maxFrequency = function(nums, k, numOperations) {
    let m = numOperations;
    nums.sort((a, b) => a - b);
    
    function lowerBound(val) {
        let left = 0, right = nums.length;
        while (left < right) {
            let mid = Math.floor((left + right) / 2);
            if (nums[mid] < val) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    function upperBound(val) {
        let left = 0, right = nums.length;
        while (left < right) {
            let mid = Math.floor((left + right) / 2);
            if (nums[mid] <= val) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    function check(n, t, m) {
        let l = lowerBound(n);
        let h = upperBound(n);
        let ll = lowerBound(n - t);
        let hh = upperBound(n + t);
        let res = (hh - h) + (l - ll);
        return Math.min(m, res) + (h - l);
    }
    
    let ans = 1;
    for (let i = 0; i < nums.length - 1; i++) {
        ans = Math.max(check(nums[i], k, m), ans);
        ans = Math.max(check(nums[i] - k, k, m), ans);
        ans = Math.max(check(nums[i] + k, k, m), ans);
    }
    return ans;
};