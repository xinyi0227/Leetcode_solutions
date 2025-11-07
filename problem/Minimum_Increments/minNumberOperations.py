class Solution:
    def minNumberOperations(self, target):
        sum_val = target[0]
        for i in range(1, len(target)):
            diff = target[i] - target[i - 1]
            if diff > 0:
                sum_val += diff
        return sum_val