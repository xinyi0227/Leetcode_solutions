class Solution:
    def maxFrequencyElements(self, nums):
        freq = [0] * 101
        maxf = 0
        res = 0
        for n in nums:
            freq[n] += 1
            f = freq[n]
            if f > maxf:
                maxf = f
                res = f
            elif f == maxf:
                res += f
        return res
