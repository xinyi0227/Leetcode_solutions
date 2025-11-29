/**
 * @param {number[]} nums
 * @param {number} original
 * @return {number}
 */
const findFinalValue = (nums, k) => {
    let bits = 0;
    for (let num of nums) {
        if (num % k !== 0) continue;
        const n = num / k;
        if ((n & (n - 1)) === 0)
            bits |= n;
    }

    return k * (++bits & -bits);
};
