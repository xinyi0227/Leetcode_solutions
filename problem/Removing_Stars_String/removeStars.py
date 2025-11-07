class Solution:
    def removeStars(self, s):
        c = ""
        for i in range(len(s)):
            if s[i] == '*':
                c = c[:-1]
            else:
                c += s[i]
        return c