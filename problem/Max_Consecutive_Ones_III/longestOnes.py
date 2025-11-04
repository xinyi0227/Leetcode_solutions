class Solution:
    def longestOnes(self, nums, k):
        l, r, zeroes, maxlen = 0, 0, 0, 0
        
        while r < len(nums):
            if nums[r] == 0:
                zeroes += 1
            
            while zeroes > k:
                if nums[l] == 0:
                    zeroes -= 1
                l += 1
            
            maxlen = max(maxlen, r - l + 1)
            r += 1
        
        return maxlen