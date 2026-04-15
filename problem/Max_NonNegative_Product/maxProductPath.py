class Solution:
    def maxProductPath(self, grid):
        r, c, MOD = len(grid), len(grid[0]), 10**9 + 7
        dp = [[[0, 0] for _ in range(c)] for _ in range(2)]
        
        p = grid[0][0]
        dp[0][0][0] = dp[0][0][1] = p
        
        for j in range(1, c):
            p *= grid[0][j]
            dp[0][j][0] = dp[0][j][1] = p
            
        p = grid[0][0]
        for i in range(1, r):
            is_odd, prv = i & 1, 1 - (i & 1)
            p *= grid[i][0]
            dp[is_odd][0][0] = dp[is_odd][0][1] = p
            
            for j in range(1, c):
                x = grid[i][j]
                vals = (x * dp[is_odd][j-1][0], x * dp[is_odd][j-1][1], 
                        x * dp[prv][j][0], x * dp[prv][j][1])
                dp[is_odd][j][0] = min(vals)
                dp[is_odd][j][1] = max(vals)
                
        ans = dp[(r - 1) & 1][c - 1][1]
        return -1 if ans < 0 else ans % MOD