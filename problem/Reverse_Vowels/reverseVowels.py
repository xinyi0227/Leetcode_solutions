class Solution:
    def reverseVowels(self, s):
        s = list(s)  
        n = len(s)
        low = 0
        high = n - 1
        vowels = set("aeiouAEIOU")
        
        while low < high:
            if s[low] in vowels and s[high] in vowels:
                s[low], s[high] = s[high], s[low]  
                low += 1
                high -= 1
            else:
                if s[high] not in vowels:
                    high -= 1
                if s[low] not in vowels:
                    low += 1
        
        return ''.join(s)
