class Solution {
    public int maxProductPath(int[][] grid) {
        int r = grid.length, c = grid[0].length, MOD = 1000000007;
        long[][][] dp = new long[2][c][2];

        long p = grid[0][0];
        dp[0][0][0] = dp[0][0][1] = p;

        for (int j = 1; j < c; j++) {
            p *= grid[0][j];
            dp[0][j][0] = dp[0][j][1] = p;
        }

        p = grid[0][0];
        for (int i = 1; i < r; i++) {
            int isOdd = i & 1, prv = 1 - isOdd;
            p *= grid[i][0];
            dp[isOdd][0][0] = dp[isOdd][0][1] = p;

            for (int j = 1; j < c; j++) {
                long x = grid[i][j];
                long v1 = x * dp[isOdd][j - 1][0], v2 = x * dp[isOdd][j - 1][1];
                long v3 = x * dp[prv][j][0], v4 = x * dp[prv][j][1];
                dp[isOdd][j][0] = Math.min(Math.min(v1, v2), Math.min(v3, v4));
                dp[isOdd][j][1] = Math.max(Math.max(v1, v2), Math.max(v3, v4));
            }
        }

        long ans = dp[(r - 1) & 1][c - 1][1];
        return ans < 0 ? -1 : (int) (ans % MOD);
    }
}