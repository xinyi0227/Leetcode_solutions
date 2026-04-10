class Solution:
    def getBiggestThree(self, grid):
        m, n = len(grid), len(grid[0])
        diag1 = [[0] * (n + 2) for _ in range(m + 1)]
        diag2 = [[0] * (n + 2) for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j]
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j]

        top3 = set()

        for i in range(m):
            for j in range(n):
                top3.add(grid[i][j])
                for k in range(1, 50):
                    if i - k < 0 or i + k >= m or j - k < 0 or j + k >= n:
                        break
                    
                    topR, topC = i - k, j
                    rightR, rightC = i, j + k
                    bottomR, bottomC = i + k, j
                    leftR, leftC = i, j - k
                    
                    border = 0
                    border += diag1[rightR + 1][rightC + 1] - diag1[topR][topC]
                    border += diag2[bottomR + 1][bottomC] - diag2[rightR][rightC + 1]
                    border += diag1[bottomR + 1][bottomC + 1] - diag1[leftR][leftC]
                    border += diag2[leftR + 1][leftC] - diag2[topR][topC + 1]
                    border -= (grid[topR][topC] + grid[rightR][rightC] + grid[bottomR][bottomC] + grid[leftR][leftC])
                    top3.add(border)

        return sorted(list(top3), reverse=True)[:3]