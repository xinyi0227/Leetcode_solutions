/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function(s) {
    const n = s.length;
    const zero = [];
    for (let i = 0; i < n; i++) if (s[i] === '0') zero.push(i);
    let ones = n - zero.length;
    zero.push(n);

    let res = 0;
    let sid = 0;

    for (let left = 0; left < n; left++) {
        for (let id = sid; id < zero.length - 1; id++) {
            const cnt0 = id - sid + 1;
            if (cnt0 * cnt0 > ones) break;
            const p = zero[id], q = zero[id + 1];
            const cnt1 = zero[id] - left - (id - sid);
            if (cnt1 >= cnt0 * cnt0) {
                res += (q - p);
            } else {
                const add = q - p - (cnt0 * cnt0 - cnt1);
                if (add > 0) res += add;
            }
        }
        if (s[left] === '0') {
            sid++;
        } else {
            res += (zero[sid] - left);
            ones--;
        }
    }
    return res;
};