/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var minCost = function(grid, k) {
    const r = grid.length;
    const c = grid[0].length;
    const N = r * c;
    const INF = 1e9 + 7;

    const x_pos = Array.from({ length: 10001 }, () => []);
    let xMax = 0;

    const idx = (i, j) => i * c + j;

    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            const x = grid[i][j];
            x_pos[x].push(idx(i, j));
            xMax = Math.max(xMax, x);
        }
    }

    const dp = new Int32Array((k + 1) * N).fill(INF);
    
    dp[0] = 0;

    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            const pos = idx(i, j);
            const x = grid[i][j];
            
            if (i > 0) {
                const prev = dp[idx(i - 1, j)];
                if (prev !== INF) dp[pos] = Math.min(dp[pos], prev + x);
            }
            if (j > 0) {
                const prev = dp[idx(i, j - 1)];
                if (prev !== INF) dp[pos] = Math.min(dp[pos], prev + x);
            }
        }
    }

    const suffixMin = new Int32Array(10001);

    for (let t = 1; t <= k; t++) {
        let currMin = INF;
        const prevOffset = (t - 1) * N;
        const currOffset = t * N;

        for (let x = xMax; x >= 0; x--) {
            const positions = x_pos[x];
            for (let m = 0; m < positions.length; m++) {
                currMin = Math.min(currMin, dp[prevOffset + positions[m]]);
            }
            suffixMin[x] = currMin;
        }

        for (let i = 0; i < r; i++) {
            for (let j = 0; j < c; j++) {
                const pos = idx(i, j);
                const actualPos = currOffset + pos;
                const x = grid[i][j];

                dp[actualPos] = Math.min(dp[prevOffset + pos], suffixMin[x]);

                if (i > 0) {
                    const up = dp[currOffset + idx(i - 1, j)];
                    if (up !== INF) dp[actualPos] = Math.min(dp[actualPos], up + x);
                }
                if (j > 0) {
                    const left = dp[currOffset + idx(i, j - 1)];
                    if (left !== INF) dp[actualPos] = Math.min(dp[actualPos], left + x);
                }
            }
        }
    }

    return dp[k * N + (N - 1)];
};