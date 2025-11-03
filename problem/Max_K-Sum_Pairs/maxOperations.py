class Solution:
    def maxOperations(self, nums, k):
        n = len(nums)
        i = 0
        j = n - 1
        count = 0
        nums.sort()
        while i < j:
            sum = nums[i] + nums[j]
            if sum == k:
                count += 1
                i += 1
                j -= 1
            if sum < k:
                i += 1
            if sum > k:
                j -= 1
        return count
