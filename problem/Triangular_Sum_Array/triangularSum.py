class Solution:
    def triangularSum(self, nums):
        n = len(nums)
        for size in range(n, 1, -1):
            for i in range(size - 1):
                nums[i] = (nums[i] + nums[i + 1]) % 10
        return nums[0]