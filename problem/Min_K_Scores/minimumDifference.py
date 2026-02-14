class Solution:
    def minimumDifference(self, nums, k):
        nums.sort()
        ans = nums[k - 1] - nums[0]
        for i in range(1, len(nums) - k + 1):
            ans = min(ans, nums[i + k - 1] - nums[i])
        return ans