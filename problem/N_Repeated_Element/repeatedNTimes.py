class Solution(object):
    def repeatedNTimes(self, nums):
        n = len(nums) - 1
        if nums[0] == nums[n]:  return nums[0]
        for i in range(n):
            if nums[i] == nums[i + 1] or nums[i] == nums[i + 2] : return nums[i]
        return nums[0]