class Solution:
    def xorAfterQueries(self, nums, queries):
        n = len(nums)
        MOD = 10**9 + 7
        limit = int(math.sqrt(n)) 
        
        lightK = defaultdict(list)
        
        for l, r, k, v in queries:
            if k >= limit:
                for i in range(l, r + 1, k):
                    nums[i] = (nums[i] * v) % MOD
            else:
                lightK[k].append((l, r, v))
                
        for k, query_list in lightK.items():

            diff = [1] * (n + k) 
            
            for l, r, v in query_list:
                diff[l] = (diff[l] * v) % MOD
                steps = (r - l) // k
                nxt = l + (steps + 1) * k
                
                inv_v = pow(v, MOD - 2, MOD)
                diff[nxt] = (diff[nxt] * inv_v) % MOD

            for i in range(n):
                if i >= k:
                    diff[i] = (diff[i] * diff[i - k]) % MOD
                nums[i] = (nums[i] * diff[i]) % MOD
                
        ans = 0
        for num in nums:
            ans ^= num
            
        return ans