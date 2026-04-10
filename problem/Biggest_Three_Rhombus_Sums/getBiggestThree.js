/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var getBiggestThree = function(grid) {
    const m = grid.length, n = grid[0].length;
    const diag1 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    const diag2 = Array.from({ length: m + 1 }, () => new Array(n + 2).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
            diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
        }
    }

    let top3 = new Set();

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            top3.add(grid[i][j]);
            for (let k = 1; i - k >= 0 && i + k < m && j - k >= 0 && j + k < n; k++) {
                const topR = i - k, topC = j;
                const rightR = i, rightC = j + k;
                const bottomR = i + k, bottomC = j;
                const leftR = i, leftC = j - k;

                let border = 0;
                border += diag1[rightR + 1][rightC + 1] - diag1[topR][topC];
                border += diag2[bottomR + 1][bottomC] - diag2[rightR][rightC + 1];
                border += diag1[bottomR + 1][bottomC + 1] - diag1[leftR][leftC];
                border += diag2[leftR + 1][leftC] - diag2[topR][topC + 1];
                border -= (grid[topR][topC] + grid[rightR][rightC] + grid[bottomR][bottomC] + grid[leftR][leftC]);
                top3.add(border);
            }
        }
    }

    return Array.from(top3).sort((a, b) => b - a).slice(0, 3);
};