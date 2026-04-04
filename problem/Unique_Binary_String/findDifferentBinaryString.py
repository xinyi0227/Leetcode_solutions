class Solution:
    def findDifferentBinaryString(self, nums):
        def b(r, q):
            t = bin(r)[2:]
            return t.zfill(q)
        
        nums.sort()
        j = 0
        n = len(nums[0])
        for i in range(len(nums) + 1):
            c = b(i, n)
            if j < len(nums) and c == nums[j]:
                j += 1
            else:
                return c
        return ""