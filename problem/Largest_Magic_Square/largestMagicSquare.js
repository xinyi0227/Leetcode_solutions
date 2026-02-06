/**
 * @param {number[][]} grid
 * @return {number}
 */
var largestMagicSquare = function(grid) {
    const r = grid.length;
    const c = grid[0].length;

    const rowSum = Array.from({ length: r }, () => new Array(c + 1).fill(0));
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
        }
    }

    const colSum = Array.from({ length: c }, () => new Array(r + 1).fill(0));
    for (let j = 0; j < c; j++) {
        for (let i = 0; i < r; i++) {
            colSum[j][i + 1] = colSum[j][i] + grid[i][j];
        }
    }

    const diag = Array.from({ length: r + 1 }, () => new Array(c + 1).fill(0));
    const antidiag = Array.from({ length: r + 1 }, () => new Array(c + 1).fill(0));

    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
            antidiag[i + 1][j] = antidiag[i][j + 1] + grid[i][j];
        }
    }

    for (let k = Math.min(r, c); k > 1; k--) {
        for (let i = 0; i <= r - k; i++) {
            for (let j = 0; j <= c - k; j++) {
                let sum = diag[i + k][j + k] - diag[i][j];
                let antiSum = antidiag[i + k][j] - antidiag[i][j + k];

                if (sum !== antiSum) continue;

                let match = true;
                for (let m = 0; m < k; m++) {
                    let rSum = rowSum[i + m][j + k] - rowSum[i + m][j];
                    let cSum = colSum[j + m][i + k] - colSum[j + m][i];
                    if (rSum !== sum || cSum !== sum) {
                        match = false;
                        break;
                    }
                }

                if (match) return k;
            }
        }
    }

    return 1;
};