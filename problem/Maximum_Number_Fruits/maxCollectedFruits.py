class Solution:
    def maxCollectedFruits(self, fruits):
        n = len(fruits)
        total = sum(fruits[i][i] for i in range(n))
        rightPath = [0] * 3
        rightPath[0] = fruits[0][n - 1]
        bottomPath = [0] * 3
        bottomPath[0] = fruits[n - 1][0]
        window = 2
        for step in range(1, n - 1):
            newRight = [0] * (window + 2)
            newBottom = [0] * (window + 2)
            for dist in range(window):
                left = rightPath[dist - 1] if dist - 1 >= 0 else 0
                mid = rightPath[dist]
                right = rightPath[dist + 1] if dist + 1 < len(rightPath) else 0
                newRight[dist] = max(left, mid, right) + fruits[step][n - 1 - dist]

                left = bottomPath[dist - 1] if dist - 1 >= 0 else 0
                mid = bottomPath[dist]
                right = bottomPath[dist + 1] if dist + 1 < len(bottomPath) else 0
                newBottom[dist] = max(left, mid, right) + fruits[n - 1 - dist][step]
            rightPath = newRight
            bottomPath = newBottom
            if window - n + 4 + step <= 1:
                window += 1
            elif window - n + 3 + step > 1:
                window -= 1
        return total + rightPath[0] + bottomPath[0]
