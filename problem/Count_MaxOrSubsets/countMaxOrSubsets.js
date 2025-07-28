/**
 * @param {number[]} nums
 * @return {number}
 */
var countMaxOrSubsets = function(nums) {
    let maxOr = 0;
    for (let n of nums) maxOr |= n;

    function dfs(index, currOr) {
        if (index === nums.length) return currOr === maxOr ? 1 : 0;
        let include = dfs(index + 1, currOr | nums[index]);
        let exclude = dfs(index + 1, currOr);
        return include + exclude;
    }

    return dfs(0, 0);
};