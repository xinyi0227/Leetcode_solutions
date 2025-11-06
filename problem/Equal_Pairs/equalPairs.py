class Solution:
    def equalPairs(self, grid):
        n = len(grid)
        m = len(grid[0])
        B1, M1 = 1000003, 1000000007
        B2, M2 = 1000033, 1000000009

        def enc_row(a):
            h1 = 0
            h2 = 0
            for x in a:
                v1 = (x + 1000000007) % M1
                v2 = (x + 1000000009) % M2
                h1 = (h1 * B1 + v1) % M1
                h2 = (h2 * B2 + v2) % M2
            return (h1, h2)

        def enc_col(j):
            h1 = 0
            h2 = 0
            for i in range(n):
                v1 = (grid[i][j] + 1000000007) % M1
                v2 = (grid[i][j] + 1000000009) % M2
                h1 = (h1 * B1 + v1) % M1
                h2 = (h2 * B2 + v2) % M2
            return (h1, h2)

        from collections import Counter
        row_count = Counter(enc_row(row) for row in grid)
        ans = 0
        for j in range(m):
            ans += row_count[enc_col(j)]
        return ans
