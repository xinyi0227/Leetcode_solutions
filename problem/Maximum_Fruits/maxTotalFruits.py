class Solution:
    def maxTotalFruits(self, fruits, startPos, k):
        def minSteps(left, right, start):
            return min(abs(start - left) + (right - left),
                       abs(start - right) + (right - left))
        
        left = 0
        sum_ = 0
        maxFruits = 0
        for right in range(len(fruits)):
            sum_ += fruits[right][1]
            while left <= right and minSteps(fruits[left][0], fruits[right][0], startPos) > k:
                sum_ -= fruits[left][1]
                left += 1
            maxFruits = max(maxFruits, sum_)
        return maxFruits
