class Solution:
    def minDeletionSize(self, strs):
        def isUnsorted(j):
            for i in range(1, len(strs)):
                if strs[i][j] < strs[i - 1][j]:
                    return True
            return False
        return sum(isUnsorted(j) for j in range(len(strs[0])))