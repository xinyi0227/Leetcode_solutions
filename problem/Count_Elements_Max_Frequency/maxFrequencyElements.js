/**
 * @param {number[]} nums
 * @return {number}
 */
const maxFrequencyElements = nums => {
    const freq = new Uint8Array(101);
    let max = 0, res = 0;
    for (const n of nums) {
        const f = ++freq[n];
        if (f > max) 
            max = f, res = f;
        else if (f === max) 
            res += f;
    }
    return res;
};
