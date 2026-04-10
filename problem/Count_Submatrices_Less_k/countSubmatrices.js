/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var countSubmatrices = function(grid, k) {
    const m = grid.length, n = grid[0].length;
    let ans = 0;
    const px = Array.from({length: m+1}, () => new Array(n+1).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            px[i+1][j+1] = grid[i][j] + px[i][j+1] + px[i+1][j] - px[i][j];
            if (px[i+1][j+1] <= k) ans++;
        }
    }
    return ans;
};