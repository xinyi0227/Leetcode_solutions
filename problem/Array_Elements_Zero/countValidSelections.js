/**
 * @param {number[]} nums
 * @return {number}
 */
var countValidSelections = function(nums) {
    let total = nums.reduce((a, b) => a + b, 0);
    let ls = 0, cases = 0;
    for (let num of nums) {
        let rs = total - ls - num;
        if (num === 0) {
            if (ls === rs) {
                cases += 2;
            } else if (ls === rs - 1 || ls - 1 === rs) {
                cases++;
            }
        }
        ls += num;
    }
    return cases;
};