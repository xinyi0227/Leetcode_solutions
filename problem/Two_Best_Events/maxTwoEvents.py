class Solution:
    def maxTwoEvents(self, events):
        events.sort()
        n = len(events)
        suffix_max = [0] * n
        suffix_max[-1] = events[-1][2]
        for i in range(n - 2, -1, -1):
            suffix_max[i] = max(events[i][2], suffix_max[i + 1])
        res = 0
        for i, (s, e, v) in enumerate(events):
            l, r = i + 1, n - 1
            idx = -1
            while l <= r:
                m = (l + r) // 2
                if events[m][0] > e:
                    idx = m
                    r = m - 1
                else:
                    l = m + 1
            if idx != -1:
                res = max(res, v + suffix_max[idx])
            res = max(res, v)
        return res