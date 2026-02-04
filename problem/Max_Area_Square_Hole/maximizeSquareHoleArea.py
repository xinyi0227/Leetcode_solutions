class Solution:
    def maximizeSquareHoleArea(self, n, m, hBars, vBars):
        def maxSpan(bars):
            bars.sort()
            res = 1
            streak = 1
            for i in range(1, len(bars)):
                if bars[i] - bars[i - 1] == 1:
                    streak += 1
                else:
                    streak = 1
                res = max(res, streak)
            return res + 1
        
        return min(maxSpan(hBars), maxSpan(vBars)) ** 2