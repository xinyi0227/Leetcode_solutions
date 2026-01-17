class Solution:
    def minimumBoxes(self, apple, capacity):
        s = sum(apple)
        freq = [0] * 51
        for c in capacity:
            freq[c] += 1

        ans = 0
        for c in range(50, 0, -1):
            while freq[c] > 0:
                s -= c
                freq[c] -= 1
                ans += 1
                if s <= 0:
                    return ans
        return ans