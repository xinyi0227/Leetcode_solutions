class Solution:
    def minCost(self, grid, k):
        r, c = len(grid), len(grid[0])
        N = r * c
        INF = 10**9 + 7
        
        x_pos = [[] for _ in range(10001)]
        x_max = 0
        
        def idx(i, j):
            return i * c + j
            
        for i in range(r):
            for j in range(c):
                x = grid[i][j]
                x_pos[x].append(idx(i, j))
                x_max = max(x_max, x)
                
        dp = [[INF] * N for _ in range(k + 1)]
        
        dp[0][0] = 0
        for i in range(r):
            for j in range(c):
                pos = idx(i, j)
                x = grid[i][j]
                if i > 0 and dp[0][idx(i-1, j)] != INF:
                    dp[0][pos] = min(dp[0][pos], dp[0][idx(i-1, j)] + x)
                if j > 0 and dp[0][idx(i, j-1)] != INF:
                    dp[0][pos] = min(dp[0][pos], dp[0][idx(i, j-1)] + x)
                    
        suffix_min = [INF] * 10001
        
        for t in range(1, k + 1):
            curr_min = INF
            for x in range(x_max, -1, -1):
                for pos in x_pos[x]:
                    curr_min = min(curr_min, dp[t-1][pos])
                suffix_min[x] = curr_min
                
            for i in range(r):
                for j in range(c):
                    pos = idx(i, j)
                    x = grid[i][j]
                    
                    dp[t][pos] = min(dp[t-1][pos], suffix_min[x])
                    
                    if i > 0 and dp[t][idx(i-1, j)] != INF:
                        dp[t][pos] = min(dp[t][pos], dp[t][idx(i-1, j)] + x)
                    if j > 0 and dp[t][idx(i, j-1)] != INF:
                        dp[t][pos] = min(dp[t][pos], dp[t][idx(i, j-1)] + x)
                        
        return dp[k][N-1]