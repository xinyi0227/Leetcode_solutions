/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var canPartitionGrid = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    let total = 0;

    const bottomFreq = new Int32Array(100001);
    const topFreq = new Int32Array(100001);
    const rightFreq = new Int32Array(100001);
    const leftFreq = new Int32Array(100001);

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x = grid[i][j];
            total += x;
            bottomFreq[x]++;
            rightFreq[x]++;
        }
    }

    let sumTop = 0;

    for (let i = 0; i < m - 1; i++) {
        for (let j = 0; j < n; j++) {
            const val = grid[i][j];
            sumTop += val;
            topFreq[val]++;
            bottomFreq[val]--;
        }

        const sumBottom = total - sumTop;

        if (sumTop === sumBottom) return true;

        const diff = Math.abs(sumTop - sumBottom);

        if (diff <= 100000) {
            if (sumTop > sumBottom) {
                if (check(topFreq, grid, 0, i, 0, n - 1, diff)) return true;
            } else {
                if (check(bottomFreq, grid, i + 1, m - 1, 0, n - 1, diff)) return true;
            }
        }
    }

    let sumLeft = 0;

    for (let j = 0; j < n - 1; j++) {
        for (let i = 0; i < m; i++) {
            const val = grid[i][j];
            sumLeft += val;
            leftFreq[val]++;
            rightFreq[val]--;
        }

        const sumRight = total - sumLeft;

        if (sumLeft === sumRight) return true;

        const diff = Math.abs(sumLeft - sumRight);

        if (diff <= 100000) {
            if (sumLeft > sumRight) {
                if (check(leftFreq, grid, 0, m - 1, 0, j, diff)) return true;
            } else {
                if (check(rightFreq, grid, 0, m - 1, j + 1, n - 1, diff)) return true;
            }
        }
    }

    return false;
};

const check = (freq, grid, r1, r2, c1, c2, diff) => {
    const rows = r2 - r1 + 1;
    const cols = c2 - c1 + 1;

    if (rows * cols === 1) return false;

    if (rows === 1) {
        return (grid[r1][c1] === diff || grid[r1][c2] === diff);
    }

    if (cols === 1) {
        return (grid[r1][c1] === diff || grid[r2][c1] === diff);
    }

    return freq[diff] > 0;
};