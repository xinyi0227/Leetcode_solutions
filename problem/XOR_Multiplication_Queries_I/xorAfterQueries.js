/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number}
 */
var xorAfterQueries = function(nums, queries) {
    const mod = 1000000007n;
    
    for (const [l, r, k, v] of queries) {
        const val = BigInt(v);
        for (let idx = l; idx <= r; idx += k) {
            nums[idx] = Number((BigInt(nums[idx]) * val) % mod);
        }
    }
    
    let ans = 0;
    for (const num of nums) {
        ans ^= num;
    }
    
    return ans;
};