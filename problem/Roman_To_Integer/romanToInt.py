class Solution(object):
    def romanToInt(self, s):
        """
        Look-ahead approach - O(n) time, O(1) space
        """
        roman_values = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50,
            'C': 100, 'D': 500, 'M': 1000
        }
        
        total = 0
        i = 0
        
        while i < len(s):
            if i + 1 < len(s) and roman_values[s[i]] < roman_values[s[i + 1]]:
                total += roman_values[s[i + 1]] - roman_values[s[i]]
                i += 2 
            else:
                total += roman_values[s[i]]
                i += 1
        
        return total
    
    def romanToInt_pattern(self, s):
        """
        Pattern matching approach
        """
        patterns = {
            'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900
        }

        values = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000
        }
        
        total = 0
        i = 0
        
        while i < len(s):
            if i + 1 < len(s) and s[i:i+2] in patterns:
                total += patterns[s[i:i+2]]
                i += 2
            else:
                total += values[s[i]]
                i += 1
        
        return total
