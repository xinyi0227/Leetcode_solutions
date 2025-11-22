/**
 * @param {string} s
 * @return {number}
 */
var maxOperations = function(s) {
    let cnt = 0, n = s.length, cnt1 = (s[0] === '1') ? 1 : 0;
    for (let i = 1; i < n; i++) {
        if (s[i] === '1') cnt1++;
        const cond = (s[i] === '0' && s[i - 1] === '1') ? 1 : 0;
        cnt += (-cond) & cnt1;
    }
    return cnt;
};