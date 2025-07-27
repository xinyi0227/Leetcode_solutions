class Solution(object):
    def countHillValley(self, nums):
        cnt = 0
        j = 0
        n = len(nums)
        
        for i in range(1, n - 1):
            if nums[i] == nums[i + 1]:
                continue
                
            if (nums[j] < nums[i] > nums[i + 1]) or (nums[j] > nums[i] < nums[i + 1]):
                cnt += 1
                j = i
                
        return cnt
