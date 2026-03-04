/**
 * @param {number[]} nums
 * @return {number}
 */
const longestBalanced = nums => {
    const n = nums.length;
    let res = 0;

    const seen = new Int32Array(Math.max(...nums) + 1);

    for (let i = 0; i < n; i++) {
        const A = [0, 0];

        for (let j = i; j < n; j++) {
            const val = nums[j];
            if (seen[val] !== i + 1) {
                seen[val] = i + 1;
                A[val & 1]++;
            }

            if (A[0] === A[1])
                res = Math.max(res, j - i + 1);
        }
    }

    return res;
};