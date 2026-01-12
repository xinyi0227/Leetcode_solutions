class Solution:
    def maxProfit(self, prices, strat, k):
        n = len(prices)
        h = k // 2

        sp = [0] * n
        base = 0
        for i in range(n):
            sp[i] = strat[i] * prices[i]
            base += sp[i]

        if n == k:
            win_orig = base
            win_mod = 0
            for i in range(h, n):
                win_mod += prices[i]
            change = win_mod - win_orig
            return base + (change if change > 0 else 0)

        win_orig = 0
        for i in range(k):
            win_orig += sp[i]

        win_mod = 0
        for i in range(h, k):
            win_mod += prices[i]

        max_ch = win_mod - win_orig

        for i in range(1, n - k + 1):
            win_orig += sp[i + k - 1] - sp[i - 1]
            win_mod += prices[i + k - 1] - prices[i - 1 + h]
            diff = win_mod - win_orig
            if diff > max_ch:
                max_ch = diff

        return base + (max_ch if max_ch > 0 else 0)