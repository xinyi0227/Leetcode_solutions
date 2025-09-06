class Solution:
    def minOperations(self, queries):
        pow4 = [1]
        while pow4[-1] <= 10**9:
            pow4.append(pow4[-1] * 4)
        prefix = [0]
        for i in range(len(pow4) - 1):
            prefix.append(prefix[-1] + (i + 1) * 3 * pow4[i])
        def F(n):
            if n <= 0:
                return 0
            k = bisect.bisect_right(pow4, n) - 1
            return prefix[k] + (k + 1) * (n - pow4[k] + 1)
        res = 0
        for l, r in queries:
            s = F(r) - F(l - 1)
            res += (s + 1) // 2
        return res
