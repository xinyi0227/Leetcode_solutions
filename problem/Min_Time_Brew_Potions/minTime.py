class Solution:
    def minTime(self, skill, mana):
        n = len(skill)
        done = [0] * (n + 1)
        for mj in mana:
            for i in range(n):
                done[i + 1] = max(done[i + 1], done[i]) + mj * skill[i]
            for i in range(n - 1, 0, -1):
                done[i] = done[i + 1] - mj * skill[i]
        return done[n]