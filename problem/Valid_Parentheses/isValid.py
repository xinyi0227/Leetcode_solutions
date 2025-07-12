class Solution(object):
    def isValid(self, s):
        """
        Stack approach - O(n) time, O(n) space
        """
        stack = []
        mapping = {')': '(', '}': '{', ']': '['}
        
        for char in s:
            if char in mapping: 
                if not stack or stack.pop() != mapping[char]:
                    return False
            else:  
                stack.append(char)
        
        return len(stack) == 0
    
    def isValid_alternative(self, s):
        """
        Alternative implementation with explicit opening bracket check
        """
        stack = []
        pairs = {'(': ')', '[': ']', '{': '}'}
        
        for char in s:
            if char in pairs:
                stack.append(char)
            else: 
                if not stack or pairs[stack.pop()] != char:
                    return False
        
        return len(stack) == 0
