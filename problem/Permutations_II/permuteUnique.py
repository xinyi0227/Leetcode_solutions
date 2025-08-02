class Solution:
    def permuteUnique(self, nums):
        nums.sort()
        res = []
        used = [False] * len(nums)
        
        def backtrack(temp):
            if len(temp) == len(nums):
                res.append(temp[:])
                return
            
            for i in range(len(nums)):
                if used[i]:
                    continue
                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue
                
                used[i] = True
                temp.append(nums[i])
                backtrack(temp)
                temp.pop()
                used[i] = False
        
        backtrack([])
        return res
