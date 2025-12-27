class Solution:
    @staticmethod
    def countCoveredBuildings(n, buildings):
        M = 0
        N = 0
        for x, y in buildings:
            if x > M:
                M = x
            if y > N:
                N = y

        xMin = [10**18] * (N + 1)
        xMax = [0] * (N + 1)
        yMin = [10**18] * (M + 1)
        yMax = [0] * (M + 1)

        for x, y in buildings:
            if x < xMin[y]:
                xMin[y] = x
            if x > xMax[y]:
                xMax[y] = x
            if y < yMin[x]:
                yMin[x] = y
            if y > yMax[x]:
                yMax[x] = y

        cnt = 0
        for x, y in buildings:
            coverX = (xMin[y] < x) & (x < xMax[y])
            coverY = (yMin[x] < y) & (y < yMax[x])
            cnt += (coverX & coverY)
        return cnt
