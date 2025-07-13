class Solution(object):
    def strStr(self, haystack, needle):
        """
        Brute force approach - O(n*m) time, O(1) space
        """
        if not needle:
            return 0
        
        haystack_len = len(haystack)
        needle_len = len(needle)

        for i in range(haystack_len - needle_len + 1):
            if haystack[i:i + needle_len] == needle:
                return i
        
        return -1
    
    def strStr_builtin(self, haystack, needle):
        """
        Using built-in find method - O(n*m) average, O(n+m) best
        """
        if not needle:
            return 0
        
        return haystack.find(needle)
    
    def strStr_manual_check(self, haystack, needle):
        """
        Manual character-by-character checking
        """
        if not needle:
            return 0
        
        haystack_len = len(haystack)
        needle_len = len(needle)
        
        for i in range(haystack_len - needle_len + 1):
            match = True
            for j in range(needle_len):
                if haystack[i + j] != needle[j]:
                    match = False
                    break
            if match:
                return i
        
        return -1
    
    def strStr_kmp(self, haystack, needle):
        """
        KMP algorithm - O(n+m) time, O(m) space
        """
        if not needle:
            return 0

        def build_lps(pattern):
            lps = [0] * len(pattern)
            length = 0
            i = 1
            
            while i < len(pattern):
                if pattern[i] == pattern[length]:
                    length += 1
                    lps[i] = length
                    i += 1
                else:
                    if length != 0:
                        length = lps[length - 1]
                    else:
                        lps[i] = 0
                        i += 1
            return lps
        
        lps = build_lps(needle)
        i = j = 0
        
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            
            if j == len(needle):
                return i - j
            elif i < len(haystack) and haystack[i] != needle[j]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        
        return -1
