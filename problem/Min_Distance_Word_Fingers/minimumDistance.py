class Solution:
    def minimumDistance(self, word):
        def cal(a, b):
            return abs(a // 6 - b // 6) + abs(a % 6 - b % 6)

        n = len(word)
        dp = [0] * 26
        
        for i in range(1, n):
            p = ord(word[i-1]) - ord('A')
            t = ord(word[i]) - ord('A')
            
            ndp = [d + cal(p, t) for d in dp]
            
            min_val = float('inf')
            for j in range(26):
                min_val = min(min_val, dp[j] + cal(j, t))
            
            ndp[p] = min(ndp[p], min_val)
            dp = ndp
            
        return min(dp)