/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
const checkStrings = (s1, s2) => {
    const freq = Array(52).fill(0);

    for (let i = 0; i < s1.length; i++) {
        const off = (i & 1) * 26;
        freq[s1.charCodeAt(i) - 97 + off]++;
        freq[s2.charCodeAt(i) - 97 + off]--;
    }

    return freq.every(c => c === 0);
};