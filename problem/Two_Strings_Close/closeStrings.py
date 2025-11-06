class Solution:
    def closeStrings(self, word1, word2):
        freq1 = [0]*26
        freq2 = [0]*26

        for ch in word1:
            freq1[ord(ch) - 97] += 1
        for ch in word2:
            freq2[ord(ch) - 97] += 1

        for i in range(26):
            if (freq1[i] == 0) != (freq2[i] == 0):
                return False

        freq1.sort()
        freq2.sort()

        for i in range(26):
            if freq1[i] != freq2[i]:
                return False

        return True
