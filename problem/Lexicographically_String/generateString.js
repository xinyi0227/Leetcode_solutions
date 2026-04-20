/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var generateString = function(s, t) {
    const n = s.length;
    const m = t.length;
    const len = n + m - 1;
    let ans = Array(len).fill('?');

    for (let i = 0; i < n; i++) {
        if (s[i] === 'T') {
            for (let j = 0; j < m; j++) {
                if (ans[i + j] !== '?' && ans[i + j] !== t[j]) {
                    return "";
                }
                ans[i + j] = t[j];
            }
        }
    }

    const old_ans = [...ans];
    for (let i = 0; i < len; i++) {
        if (ans[i] === '?') ans[i] = 'a';
    }

    for (let i = 0; i < n; i++) {
        if (s[i] === 'F') {
            let currentSub = ans.slice(i, i + m).join('');
            if (currentSub === t) {
                let ok = false;
                for (let j = i + m - 1; j >= i; j--) {
                    if (old_ans[j] === '?') {
                        ans[j] = 'b';
                        ok = true;
                        break;
                    }
                }
                if (!ok) return "";
            }
        }
    }

    return ans.join('');
};