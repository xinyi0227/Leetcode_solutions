class Solution:
    def minimumTotalDistance(self, robot, factory):
        robot.sort()
        factory.sort()
        
        n = len(robot)
        m = len(factory)
        dp = [[-1] * m for _ in range(n)]

        def solve(i, j):
            if i == n:
                return 0
            if j == m:
                return int(1e15)
            if dp[i][j] != -1:
                return dp[i][j]

            res = solve(i, j + 1)
            cost = 0
            pos = factory[j][0]
            limit = factory[j][1]

            for k in range(limit):
                if i + k >= n:
                    break
                cost += abs(robot[i + k] - pos)
                res = min(res, cost + solve(i + k + 1, j + 1))

            dp[i][j] = res
            return res

        return solve(0, 0)