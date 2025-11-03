class Solution:
    def findMaxAverage(self, nums, k):

        windowSum = 0

        for i in range(k):
            windowSum += nums[i]
        maxSum = windowSum

        for i in range(k, len(nums)):
            windowSum = windowSum + nums[i] - nums[i - k]
            if windowSum > maxSum:
                maxSum = windowSum
                
        return float(maxSum) / float(k)
