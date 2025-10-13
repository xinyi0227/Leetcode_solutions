class Solution:
    def maximumEnergy(self, energy, k):
        n = len(energy)
        dp = [0] * n
        res = -10**18
        for i in range(n - 1, -1, -1):
            dp[i] = energy[i] + (dp[i + k] if i + k < n else 0)
            if dp[i] > res:
                res = dp[i]
        return res