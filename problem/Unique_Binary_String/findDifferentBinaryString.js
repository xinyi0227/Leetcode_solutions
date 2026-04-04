/**
 * @param {string[]} nums
 * @return {string}
 */
var findDifferentBinaryString = function(nums) {
    const b = (r, q) => {
        let t = r.toString(2);
        while (t.length < q) {
            t = '0' + t;
        }
        return t;
    };

    let j = 0;
    nums.sort();
    for (let i = 0; i <= nums.length; i++) {
        let c = b(i, nums[0].length);
        if (j < nums.length && c === nums[j]) {
            j++;
        } else {
            return c;
        }
    }
    return "";
};