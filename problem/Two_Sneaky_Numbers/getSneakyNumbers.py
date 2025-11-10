class Solution:
    def getSneakyNumbers(self, nums):
        n = len(nums)
        seen = [False] * n
        res = []
        for x in nums:
            if x < n and seen[x]:
                res.append(x)
            elif x < n:
                seen[x] = True
        return res