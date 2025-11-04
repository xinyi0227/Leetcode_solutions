class Solution:
    def largestAltitude(self, gain):
        alt = 0 
        best = 0

        for g in gain:
            alt += g
            best = max(best, alt)

        return best