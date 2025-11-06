/**
 * @param {number[][]} grid
 * @return {number}
 */
var equalPairs = function(grid) {
    const n = grid.length, m = grid[0].length;
    const B1 = 1000003n, M1 = 1000000007n;
    const B2 = 1000033n, M2 = 1000000009n;

    const encodeRow = (arr) => {
        let h1 = 0n, h2 = 0n;
        for (let x of arr) {
            let v1 = BigInt(x) + 1000000007n;
            let v2 = BigInt(x) + 1000000009n;
            h1 = (h1 * B1 + v1) % M1;
            h2 = (h2 * B2 + v2) % M2;
        }
        return h1.toString() + "#" + h2.toString();
    };
    const encodeCol = (j) => {
        let h1 = 0n, h2 = 0n;
        for (let i = 0; i < n; i++) {
            let v1 = BigInt(grid[i][j]) + 1000000007n;
            let v2 = BigInt(grid[i][j]) + 1000000009n;
            h1 = (h1 * B1 + v1) % M1;
            h2 = (h2 * B2 + v2) % M2;
        }
        return h1.toString() + "#" + h2.toString();
    };

    const map = new Map();
    for (let i = 0; i < n; i++) {
        const k = encodeRow(grid[i]);
        map.set(k, (map.get(k) || 0) + 1);
    }
    let ans = 0;
    for (let j = 0; j < m; j++) {
        const k = encodeCol(j);
        ans += (map.get(k) || 0);
    }
    return ans;
};

var closeStrings = function(word1, word2) {
    const f1 = new Array(26).fill(0);
    const f2 = new Array(26).fill(0);
    for (const ch of word1) f1[ch.charCodeAt(0) - 97]++;
    for (const ch of word2) f2[ch.charCodeAt(0) - 97]++;
    for (let i = 0; i < 26; i++) {
        if ((f1[i] === 0) !== (f2[i] === 0)) return false;
    }
    f1.sort((a,b)=>a-b);
    f2.sort((a,b)=>a-b);
    for (let i = 0; i < 26; i++) if (f1[i] !== f2[i]) return false;
    return true;
};
