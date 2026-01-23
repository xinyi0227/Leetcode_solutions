/**
 * @param {string} bottom
 * @param {string[]} allowed
 * @return {boolean}
 */
var pyramidTransition = function(bottom, allowed) {
    const pattern = new Uint8Array(36);
    const BAD = Array.from({ length: 8 }, () => new Set());

    for (const s of allowed) {
        const idx = (s.charCodeAt(0) - 65) * 6 + (s.charCodeAt(1) - 65);
        pattern[idx] |= 1 << (s.charCodeAt(2) - 65);
    }

    const encode = (s) => {
        let ans = 0;
        for (let i = 0; i < s.length; i++) {
            ans = ans * 7 + (s.charCodeAt(i) - 65);
        }
        return ans;
    };

    const check = (cur, sz) => {
        for (let i = 0; i < sz - 1; i++) {
            if (cur[i] === 'G') return false;
            const key = (cur.charCodeAt(i) - 65) * 6 + (cur.charCodeAt(i + 1) - 65);
            if (!pattern[key]) return false;
        }
        return true;
    };

    const dfs = (cur, nextArr, i, sz) => {
        if (i === sz - 1) {
            if (sz === 2) return true;
            const nextStr = nextArr.join('');
            if (!check(nextStr, sz - 1)) return false;

            const idx = encode(nextStr);
            if (BAD[sz - 1].has(idx)) return false;

            const up = new Array(sz - 2).fill('G');
            if (!dfs(nextStr, up, 0, sz - 1)) {
                BAD[sz - 1].add(idx);
                return false;
            }
            return true;
        }

        const key = (cur.charCodeAt(i) - 65) * 6 + (cur.charCodeAt(i + 1) - 65);
        let mask = pattern[key];

        while (mask) {
            const bit = mask & -mask;
            mask -= bit;
            
            const c = 31 - Math.clz32(bit);
            nextArr[i] = String.fromCharCode(65 + c);
            
            if (dfs(cur, nextArr, i + 1, sz)) return true;
        }
        return false;
    };

    const nextArr = new Array(bottom.length - 1).fill('G');
    return dfs(bottom, nextArr, 0, bottom.length);
};