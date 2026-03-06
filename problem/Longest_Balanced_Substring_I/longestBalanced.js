/**
 * @param {string} s
 * @return {number}
 */
var longestBalanced = function(s) {
    let cnt = 1;
    const n = s.length;
    const freq = new Int32Array(26);

    for (let l = 0; l < n; l++) {
        freq.fill(0);
        let uniq = 0, maxF = 0, cntMax = 0;
        
        for (let r = l; r < n; r++) {
            const idx = s.charCodeAt(r) - 97;
            const f = ++freq[idx];

            if (f === 1) uniq++;

            if (f > maxF) {
                maxF = f;
                cntMax = 1;
            } else if (f === maxF) {
                cntMax++;
            }

            if (uniq === cntMax) {
                cnt = Math.max(cnt, r - l + 1);
            }
        }
    }
    return cnt;
};