class Solution:
    def countOdds(self, low, high):
        odd = (high - low) // 2
        if low % 2 == 1 or high % 2 == 1:
            odd += 1
        return odd
