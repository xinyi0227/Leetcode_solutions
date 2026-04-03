class Solution:
    def minOperations(self, s):
        count, n = 0, len(s)
        for i in range(n):
            count += (ord(s[i]) ^ i) & 1
            
        return min(count, n - count)