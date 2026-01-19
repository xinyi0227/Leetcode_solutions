class Solution:
    def maximumHappinessSum(self, happiness, k):
        happiness.sort()
        
        total_sum = 0
        n = len(happiness)
        
        for i in range(k):
            x = max(0, happiness[n - 1 - i] - i)
            total_sum += x
            
        return total_sum