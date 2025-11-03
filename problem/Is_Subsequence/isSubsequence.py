class Solution(object):
    def isSubsequence(self, s, t):
        counts = 0
        slen = len(s)
        
        if slen == 0:
            return True
        
        for ch in t:
            if s[counts] == ch:
                counts += 1
                if counts == slen:
                    return True
        return False