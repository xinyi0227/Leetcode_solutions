/**
 * @param {number[][]} mat
 * @param {number} threshold
 * @return {number}
 */
var maxSideLength = function(mat, threshold) {
    const m = mat.length;
    const n = mat[0].length;
    
    const pref = Array.from({ length: m + 1 }, () => new Int32Array(n + 1));

    for (let row = 1; row <= m; row++) {
        for (let col = 1; col <= n; col++) {
            pref[row][col] = mat[row - 1][col - 1] + pref[row - 1][col] + pref[row][col - 1] - pref[row - 1][col - 1];
        }
    }

    let maxLen = 0;

    for (let row = 1; row <= m; row++) {
        for (let col = 1; col <= n; col++) {
            let currentLen = maxLen + 1;

            if (row >= currentLen && col >= currentLen) {
                let r1 = row - currentLen + 1;
                let c1 = col - currentLen + 1;

                let squareSum = pref[row][col] - pref[r1 - 1][col] - pref[row][c1 - 1] + pref[r1 - 1][c1 - 1];

                if (squareSum <= threshold) {
                    maxLen++;
                }
            }
        }
    }

    return maxLen;
};