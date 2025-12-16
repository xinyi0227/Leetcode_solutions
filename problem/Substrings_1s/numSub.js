/**
 * @param {string} s
 * @return {number}
 */
var numSub = function(s) {
    let cnt = 0, total = 0, mod = 1000000007;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '1') {
            cnt++;
        } else {
            cnt = 0;
        }
        total = (total + cnt) % mod;
    }
    return total;
};