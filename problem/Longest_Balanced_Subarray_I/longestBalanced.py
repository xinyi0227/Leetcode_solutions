class Solution:
    def longestBalanced(self, nums):
        n = len(nums)
        res = 0
        seen_arr = [0] * 100001
        leet = 1 
        
        for i in range(n):
            if n - i <= res:
                break
                
            counts = [0, 0]
            marker = (leet << 16) | (i + 1)
            
            for j in range(i, n):
                val = nums[j]
                if seen_arr[val] != marker:
                    seen_arr[val] = marker
                    counts[val & 1] += 1
                
                if counts[0] == counts[1]:
                    res = max(res, j - i + 1)
        
        return res