class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        Vertical scanning approach - O(S) time, O(1) space
        where S is the sum of all characters in all strings
        """
        if not strs:
            return ""
        
        min_len = min(len(s) for s in strs)
        
        for i in range(min_len):
            char = strs[0][i]

            for j in range(1, len(strs)):
                if strs[j][i] != char:
                    return strs[0][:i]
        
        return strs[0][:min_len]
    
    def longestCommonPrefix_horizontal(self, strs):
        """
        Horizontal scanning approach
        """
        if not strs:
            return ""
        
        prefix = strs[0]
        
        for i in range(1, len(strs)):
            j = 0
            while j < len(prefix) and j < len(strs[i]) and prefix[j] == strs[i][j]:
                j += 1
            prefix = prefix[:j]

            if not prefix:
                return ""
        
        return prefix
    
    def longestCommonPrefix_divide_conquer(self, strs):
        """
        Divide and conquer approach
        """
        def common_prefix(left, right):
            min_len = min(len(left), len(right))
            for i in range(min_len):
                if left[i] != right[i]:
                    return left[:i]
            return left[:min_len]
        
        def divide_conquer(strs, l, r):
            if l == r:
                return strs[l]
            
            mid = (l + r) // 2
            left_prefix = divide_conquer(strs, l, mid)
            right_prefix = divide_conquer(strs, mid + 1, r)
            
            return common_prefix(left_prefix, right_prefix)
        
        if not strs:
            return ""
        
        return divide_conquer(strs, 0, len(strs) - 1)
