class Solution:
    def minAbsDiff(self, grid, k):
        m, n = len(grid), len(grid[0])
        ans = [[0] * (n - k + 1) for _ in range(m - k + 1)]

        for i in range(m - k + 1):
            for j in range(n - k + 1):
                v = []
                for x in range(i, i + k):
                    for y in range(j, j + k):
                        v.append(grid[x][y])
                
                v = sorted(list(set(v)))
                
                if len(v) <= 1:
                    ans[i][j] = 0
                else:
                    mn = float('inf')
                    for p in range(len(v) - 1):
                        mn = min(mn, v[p+1] - v[p])
                    ans[i][j] = mn
                    
        return ans