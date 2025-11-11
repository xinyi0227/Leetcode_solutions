class Solution:
    def findXSum(self, nums, k, x):
        def find(mp, x):
            items = [(-freq, -val) for val, freq in mp.items()]
            items.sort()
            sum_val = 0
            for i in range(min(len(items), x)):
                sum_val += (-items[i][0]) * (-items[i][1])
            return sum_val
        
        mp = {}
        v = []
        l, r = 0, 0
        while r < len(nums):
            mp[nums[r]] = mp.get(nums[r], 0) + 1
            while l < r and r - l + 1 > k:
                mp[nums[l]] -= 1
                if mp[nums[l]] == 0:
                    del mp[nums[l]]
                l += 1
            if r - l + 1 == k:
                v.append(find(mp, x))
            r += 1
        return v