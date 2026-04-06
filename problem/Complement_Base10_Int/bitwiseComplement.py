class Solution:
    def bitwiseComplement(self, n):
        if n == 0: return 1
        mask = n
        for i in (1, 2, 4, 8, 16):
            mask |= mask >> i
        return ~n & mask