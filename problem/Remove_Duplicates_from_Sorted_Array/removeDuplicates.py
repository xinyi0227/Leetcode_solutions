class Solution(object):
    def removeDuplicates(self, nums):
        """
        Two-pointer approach - O(n) time, O(1) space
        """
        if not nums:
            return 0
        
        slow = 0  
        
        for fast in range(1, len(nums)):
            if nums[fast] != nums[slow]:
                slow += 1
                nums[slow] = nums[fast]
        
        return slow + 1
    
    def removeDuplicates_alternative(self, nums):
        """
        Alternative implementation with explicit write index
        """
        if not nums:
            return 0
        
        write_index = 1  
        
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[write_index] = nums[i]
                write_index += 1
        
        return write_index
