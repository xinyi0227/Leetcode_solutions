/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findXSum = function(nums, k, x) {
    function find(mp, x) {
        let items = Array.from(mp.entries()).map(([val, freq]) => [freq, val]);
        items.sort((a, b) => {
            if (a[0] === b[0]) return b[1] - a[1];
            return b[0] - a[0];
        });
        let sum = 0;
        for (let i = 0; i < items.length && i < x; i++) {
            sum += items[i][0] * items[i][1];
        }
        return sum;
    }
    
    let mp = new Map();
    let v = [];
    let l = 0, r = 0;
    while (r < nums.length) {
        mp.set(nums[r], (mp.get(nums[r]) || 0) + 1);
        while (l < r && r - l + 1 > k) {
            mp.set(nums[l], mp.get(nums[l]) - 1);
            if (mp.get(nums[l]) === 0) {
                mp.delete(nums[l]);
            }
            l++;
        }
        if (r - l + 1 === k) {
            v.push(find(mp, x));
        }
        r++;
    }
    return v;
};