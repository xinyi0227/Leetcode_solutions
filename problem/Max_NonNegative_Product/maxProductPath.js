/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxProductPath = function(grid) {
    const r = grid.length, c = grid[0].length, MOD = 1e9 + 7;
    let dp = Array.from({ length: 2 }, () => Array.from({ length: c }, () => [0, 0]));

    let p = grid[0][0];
    dp[0][0][0] = dp[0][0][1] = BigInt(p);

    for (let j = 1; j < c; j++) {
        p *= grid[0][j];
        dp[0][j][0] = dp[0][j][1] = BigInt(p);
    }

    p = grid[0][0];
    for (let i = 1; i < r; i++) {
        let isOdd = i & 1, prv = 1 - isOdd;
        p *= grid[i][0];
        dp[isOdd][0][0] = dp[isOdd][0][1] = BigInt(p);

        for (let j = 1; j < c; j++) {
            let x = BigInt(grid[i][j]);
            let vals = [
                x * dp[isOdd][j - 1][0], x * dp[isOdd][j - 1][1],
                x * dp[prv][j][0], x * dp[prv][j][1]
            ];
            dp[isOdd][j][0] = vals.reduce((a, b) => a < b ? a : b);
            dp[isOdd][j][1] = vals.reduce((a, b) => a > b ? a : b);
        }
    }

    let ans = dp[(r - 1) & 1][c - 1][1];
    return ans < 0n ? -1 : Number(ans % BigInt(MOD));
};