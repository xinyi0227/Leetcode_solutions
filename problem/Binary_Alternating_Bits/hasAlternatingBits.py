class Solution:
    def hasAlternatingBits(self, n):
        return (n & (n >> 1)) == 0 and (n & (n >> 2)) == (n >> 2)