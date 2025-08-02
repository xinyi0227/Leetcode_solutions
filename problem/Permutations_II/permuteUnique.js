/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    nums.sort((a,b) => a - b);
    const res = [];
    const temp = [];
    const used = new Array(nums.length).fill(false);

    function backtrack() {
        if (temp.length === nums.length) {
            res.push([...temp]);
            return;
        }
        for (let i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] === nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            temp.push(nums[i]);
            backtrack();
            temp.pop();
            used[i] = false;
        }
    }

    backtrack();
    return res;
};
