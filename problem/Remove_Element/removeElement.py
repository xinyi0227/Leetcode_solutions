class Solution(object):
    def removeElement(self, nums, val):
        """
        Two-pointer approach - O(n) time, O(1) space
        """
        slow = 0 
        
        for fast in range(len(nums)):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
        
        return slow
    
    def removeElement_swap(self, nums, val):
        """
        Swap with end approach - optimized for fewer writes
        """
        i = 0
        n = len(nums)
        
        while i < n:
            if nums[i] == val:
                nums[i] = nums[n - 1]
                n -= 1
            else:
                i += 1
        
        return n
    
    def removeElement_while(self, nums, val):
        """
        While loop implementation
        """
        slow = 0
        fast = 0
        
        while fast < len(nums):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        
        return slow
