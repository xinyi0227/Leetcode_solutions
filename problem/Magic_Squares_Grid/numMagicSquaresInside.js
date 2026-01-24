/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function(grid) {
    const isValid = (i, j, grid) => {
        let count = new Array(10).fill(0);
        for (let x = 0; x < 3; ++x) {
            for (let y = 0; y < 3; ++y) {
                let num = grid[i + x][j + y];
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }

        let sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

        for (let x = 0; x < 3; ++x) {
            if (sum !== (grid[i + x][j] + grid[i + x][j + 1] + grid[i + x][j + 2])) return false;
        }

        for (let y = 0; y < 3; ++y) {
            if (sum !== (grid[i][j + y] + grid[i + 1][j + y] + grid[i + 2][j + y])) return false;
        }

        if (sum !== (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2])) return false;
        if (sum !== (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2])) return false;

        return true;
    };

    let cnt = 0;
    let row = grid.length;
    let col = grid[0].length;

    if (row < 3 || col < 3) return 0;

    for (let i = 0; i <= row - 3; ++i) {
        for (let j = 0; j <= col - 3; ++j) {
            if (isValid(i, j, grid)) cnt++;
        }
    }
    return cnt;
};