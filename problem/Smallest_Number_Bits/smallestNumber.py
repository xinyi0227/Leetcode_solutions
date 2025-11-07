class Solution:
    def smallestNumber(self, n):
        while n & (n + 1):
            n |= n + 1
        return n