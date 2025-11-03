class Solution:
    def hasSameDigits(self, s):
        s = list(s)
        iteration = 0
        
        while len(s) - iteration != 2:
            for i in range(len(s) - 1 - iteration):
                s[i] = str((int(s[i]) + int(s[i + 1])) % 10)
            iteration += 1
        
        return s[0] == s[1]