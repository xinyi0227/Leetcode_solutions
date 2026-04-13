/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var minAbsDiff = function(grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    const ans = Array.from({ length: m - k + 1 }, () => new Array(n - k + 1));

    for (let i = 0; i <= m - k; i++) {
        for (let j = 0; j <= n - k; j++) {
            let v = [];
            for (let x = i; x < i + k; x++) {
                for (let y = j; y < j + k; y++) {
                    v.push(grid[x][y]);
                }
            }

            v.sort((a, b) => a - b);
            v = [...new Set(v)];

            if (v.length <= 1) {
                ans[i][j] = 0;
            } else {
                let mn = Infinity;
                for (let p = 0; p < v.length - 1; p++) {
                    mn = Math.min(mn, v[p + 1] - v[p]);
                }
                ans[i][j] = mn;
            }
        }
    }
    return ans;
};