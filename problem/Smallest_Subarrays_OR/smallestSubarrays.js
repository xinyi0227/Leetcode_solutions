/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallestSubarrays = function(nums) {
    let n = nums.length;
    let res = new Array(n);
    let suf = new Array(n);
    suf[n-1] = nums[n-1];
    for(let i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] | nums[i];
    }
    let l = 0, r = 0;
    let cur = nums[0];
    let freq = new Array(32).fill(0);
    for(let j = 0; j < 32; j++) {
        if((nums[0] & (1 << j)) !== 0) {
            freq[j]++;
        }
    }
    while (l < n) {
        while (r + 1 < n && cur !== suf[l]) {
            r++;
            cur |= nums[r];
            for(let j = 0; j < 32; j++) {
                if((nums[r] & (1 << j)) !== 0) {
                    freq[j]++;
                }
            }
        }
        res[l] = Math.max(1, r - l + 1);
        for(let j = 0; j < 32; j++) {
            if((nums[l] & (1 << j)) !== 0) {
                freq[j]--;
                if(freq[j] === 0) {
                    cur = cur & (~(1 << j));
                }
            }
        }
        l++;
    }
    return res;
};