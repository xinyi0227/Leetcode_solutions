/**
 * @param {string} s
 * @return {number}
 */
const minOperations = s => {
    let count = 0, n = s.length;
    for (let i = 0; i < s.length; i++)
        if (s[i] ^ (i & 1)) count++;

    return Math.min(count, n - count);
};