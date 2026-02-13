class Solution:
    def minPairSum(self, nums):
        nums.sort()
        res = 0
        n = len(nums)
        
        for i in range(n // 2):
            res = max(res, nums[i] + nums[n - 1 - i])
            
        return res