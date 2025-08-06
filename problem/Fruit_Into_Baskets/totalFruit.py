class Solution:
    def totalFruit(self, fruits):
        n = len(fruits)
        ans = 0
        basket = [-1, -1]
        cnt = [0, 0]
        lastRun = 0
        
        for i in range(n):
            x = fruits[i]
            if x == basket[1]:
                cnt[1] += 1
                lastRun += 1
            elif x == basket[0]:
                basket[0], basket[1] = basket[1], basket[0]
                cnt[0], cnt[1] = cnt[1], cnt[0]
                cnt[1] += 1
                lastRun = 1
            else:
                basket[0] = basket[1]
                basket[1] = x
                cnt[0] = lastRun
                lastRun = 1
                cnt[1] = 1
            ans = max(ans, cnt[0] + cnt[1])
        return ans
