class Solution:
    def sortByBits(self, arr):
        arr.sort(key=lambda x: (bin(x).count('1'), x))
        return arr