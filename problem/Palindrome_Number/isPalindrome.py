class Solution(object):
    def isPalindrome(self, x):
        """
        Mathematical approach - O(log n) time, O(1) space
        """
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        
        reversed_half = 0
        while x > reversed_half:
            reversed_half = reversed_half * 10 + x % 10
            x //= 10

        return x == reversed_half or x == reversed_half // 10

    def isPalindrome_string(self, x):
        """
        String conversion approach - O(log n) time, O(log n) space
        """
        if x < 0:
            return False
        
        s = str(x)
        left, right = 0, len(s) - 1
        
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        
        return True
