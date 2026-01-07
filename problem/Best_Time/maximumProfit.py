class Solution:
    def maximumProfit(self, A, k):
        res = [0] * (k + 1)
        bought = [-10**9] * k
        sold = [0] * k

        for a in A:
            for j in range(k, 0, -1):
                res[j] = max(res[j], bought[j - 1] + a, sold[j - 1] - a)
                bought[j - 1] = max(bought[j - 1], res[j - 1] - a)
                sold[j - 1] = max(sold[j - 1], res[j - 1] + a)
        
        return max(res)