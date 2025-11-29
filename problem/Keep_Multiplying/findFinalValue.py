class Solution:
    def findFinalValue(self, nums, original):
        bits = 0
        for n in nums:
            if n % original != 0:
                continue
            n //= original
            if (n & (n - 1)) == 0:
                bits |= n
        
        bits += 1
        return original * (bits & -bits)