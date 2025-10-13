class Solution:
    def maximumTotalDamage(self, power):
        if not power:
            return 0
        freq = {}
        for p in power:
            freq[p] = freq.get(p, 0) + 1
        keys = sorted(freq)
        n = len(keys)
        dp = [0] * n
        dp[0] = freq[keys[0]] * keys[0]
        for i in range(1, n):
            take = freq[keys[i]] * keys[i]
            x = keys[i] - 3
            lo, hi = 0, i
            while lo < hi:
                mid = (lo + hi) // 2
                if keys[mid] <= x:
                    lo = mid + 1
                else:
                    hi = mid
            prev = lo - 1
            if prev >= 0:
                take += dp[prev]
            dp[i] = dp[i - 1] if dp[i - 1] > take else take
        return dp[-1]