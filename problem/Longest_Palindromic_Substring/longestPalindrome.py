class Solution(object):
    def longestPalindrome(self, s):
        """
        Expand around centers - O(n^2) time, O(1) space
        """
        if not s:
            return ""
        
        start = 0
        max_len = 1
        
        for i in range(len(s)):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i + 1)
            
            current_max = max(len1, len2)
            if current_max > max_len:
                max_len = current_max
                start = i - (current_max - 1) // 2
        
        return s[start:start + max_len]
    
    def expandAroundCenter(self, s, left, right):
        """Helper function to expand around center"""
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1
    
    def longestPalindrome_dp(self, s):
        """
        Dynamic programming approach - O(n^2) time, O(n^2) space
        """
        n = len(s)
        if n == 0:
            return ""

        dp = [[False] * n for _ in range(n)]
        start = 0
        max_len = 1

        for i in range(n):
            dp[i][i] = True

        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                start = i
                max_len = 2

        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    start = i
                    max_len = length
        
        return s[start:start + max_len]
    
    def longestPalindrome_manacher(self, s):
        """
        Manacher's algorithm - O(n) time, O(n) space
        """
        processed = "^#" + "#".join(s) + "#$"
        n = len(processed)

        lengths = [0] * n
        center = right = 0
        
        for i in range(1, n - 1):
            mirror = 2 * center - i

            if i < right:
                lengths[i] = min(right - i, lengths[mirror])

            while processed[i + lengths[i] + 1] == processed[i - lengths[i] - 1]:
                lengths[i] += 1

            if i + lengths[i] > right:
                center, right = i, i + lengths[i]

        max_len = 0
        center_index = 0
        for i in range(1, n - 1):
            if lengths[i] > max_len:
                max_len = lengths[i]
                center_index = i

        start = (center_index - max_len) // 2
        return s[start:start + max_len]
