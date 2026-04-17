class Solution:
    def canPartitionGrid(self, grid):
        m, n = len(grid), len(grid[0])
        total = 0
        
        bottomFreq = [0] * 100001
        topFreq = [0] * 100001
        rightFreq = [0] * 100001
        leftFreq = [0] * 100001

        for row in grid:
            for x in row:
                total += x
                bottomFreq[x] += 1
                rightFreq[x] += 1

        sumTop = 0

        for i in range(m - 1):
            for j in range(n):
                val = grid[i][j]
                sumTop += val
                topFreq[val] += 1
                bottomFreq[val] -= 1

            sumBottom = total - sumTop

            if sumTop == sumBottom:
                return True

            diff = abs(sumTop - sumBottom)

            if diff <= 100000:
                if sumTop > sumBottom:
                    if self.check(topFreq, grid, 0, i, 0, n - 1, diff):
                        return True
                else:
                    if self.check(bottomFreq, grid, i + 1, m - 1, 0, n - 1, diff):
                        return True

        sumLeft = 0

        for j in range(n - 1):
            for i in range(m):
                val = grid[i][j]
                sumLeft += val
                leftFreq[val] += 1
                rightFreq[val] -= 1

            sumRight = total - sumLeft

            if sumLeft == sumRight:
                return True

            diff = abs(sumLeft - sumRight)

            if diff <= 100000:
                if sumLeft > sumRight:
                    if self.check(leftFreq, grid, 0, m - 1, 0, j, diff):
                        return True
                else:
                    if self.check(rightFreq, grid, 0, m - 1, j + 1, n - 1, diff):
                        return True

        return False

    def check(self, freq, grid, r1, r2, c1, c2, diff):
        rows = r2 - r1 + 1
        cols = c2 - c1 + 1

        if rows * cols == 1:
            return False

        if rows == 1:
            return grid[r1][c1] == diff or grid[r1][c2] == diff

        if cols == 1:
            return grid[r1][c1] == diff or grid[r2][c1] == diff

        return freq[diff] > 0