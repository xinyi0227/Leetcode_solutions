class Solution:
    def maxPartitionsAfterOperations(self, s, k):
        memo = {}
        def dp(i, mask, canChange):
            if i == len(s):
                return 0
            key = (i, mask, canChange)
            if key in memo:
                return memo[key]
            bit = ord(s[i]) - ord('a')
            newMask = mask | (1 << bit)
            if bin(newMask).count('1') > k:
                res = 1 + dp(i + 1, 1 << bit, canChange)
            else:
                res = dp(i + 1, newMask, canChange)
            if canChange:
                for j in range(26):
                    changeMask = mask | (1 << j)
                    if bin(changeMask).count('1') > k:
                        res = max(res, 1 + dp(i + 1, 1 << j, False))
                    else:
                        res = max(res, dp(i + 1, changeMask, False))
            memo[key] = res
            return res
        return dp(0, 0, True) + 1