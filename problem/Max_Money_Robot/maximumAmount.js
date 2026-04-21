/**
 * @param {number[][]} coins
 * @return {number}
 */
var maximumAmount = function(coins) {
    const n = coins.length;
    const m = coins[0].length;
    const INF = 1e9;
    
    const dp = Array.from({ length: n }, () => 
        Array.from({ length: m }, () => Array(3).fill(-INF))
    );

    dp[0][0][0] = coins[0][0];
    dp[0][0][1] = 0;
    dp[0][0][2] = 0;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            for (let k = 0; k < 3; k++) {
                if (i > 0) {
                    dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                    if (k > 0) {
                        dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j][k - 1]);
                    }
                }
                if (j > 0) {
                    dp[i][j][k] = Math.max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                    if (k > 0) {
                        dp[i][j][k] = Math.max(dp[i][j][k], dp[i][j - 1][k - 1]);
                    }
                }
            }
        }
    }

    return Math.max(...dp[n - 1][m - 1]);
};