class Solution:
    def isPossible(self, m, n, t, cells):
        grid = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(t):
            r, c = cells[i]
            grid[r][c] = 1

        q = deque()
        for c in range(1, n + 1):
            if grid[1][c] == 0:
                q.append((1, c))
                grid[1][c] = 1

        dirs = ((1, 0), (-1, 0), (0, 1), (0, -1))
        while q:
            r, c = q.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 < nr <= m and 0 < nc <= n and grid[nr][nc] == 0:
                    grid[nr][nc] = 1
                    if nr == m:
                        return True
                    q.append((nr, nc))
        return False

    def latestDayToCross(self, row, col, cells):
        left, right, ans = 0, row * col, 0
        while left < right - 1:
            mid = left + (right - left) // 2
            if self.isPossible(row, col, mid, cells):
                left = mid
                ans = mid
            else:
                right = mid
        return ans