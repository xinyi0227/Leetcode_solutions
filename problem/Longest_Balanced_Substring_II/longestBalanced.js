/**
 * @param {string} s
 * @return {number}
 */
var longestBalanced = function(s) {
    const calc1 = (s) => {
        let res = 0;
        let n = s.length;
        for (let i = 0; i < n;) {
            let j = i;
            while (j < n && s[j] === s[i]) j++;
            res = Math.max(res, j - i);
            i = j;
        }
        return res;
    };

    const calc2 = (s, a, b) => {
        let res = 0, n = s.length, i = 0;
        while (i < n) {
            while (i < n && s[i] !== a && s[i] !== b) i++;
            let mp = new Map();
            mp.set(0, i - 1);
            let diff = 0;
            while (i < n && (s[i] === a || s[i] === b)) {
                diff += (s[i] === a ? 1 : -1);
                if (mp.has(diff)) {
                    res = Math.max(res, i - mp.get(diff));
                } else {
                    mp.set(diff, i);
                }
                i++;
            }
        }
        return res;
    };

    const calc3 = (s) => {
        let mp = new Map();
        mp.set("0,0", -1);
        let cnt = [0, 0, 0];
        let res = 0;
        for (let i = 0; i < s.length; i++) {
            cnt[s.charCodeAt(i) - 97]++;
            let x = cnt[0] - cnt[1];
            let y = cnt[1] - cnt[2];
            let key = `${x},${y}`;
            if (mp.has(key)) {
                res = Math.max(res, i - mp.get(key));
            } else {
                mp.set(key, i);
            }
        }
        return res;
    };

    let x = calc1(s);
    let y = Math.max(
        calc2(s, 'a', 'b'),
        calc2(s, 'b', 'c'),
        calc2(s, 'a', 'c')
    );
    let z = calc3(s);
    return Math.max(x, y, z);
};