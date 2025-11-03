class Solution:
    def totalMoney(self, days):
        nWeeks = days // 7
        rDays = days % 7
        triSum = lambda n: (n * (n + 1)) >> 1
        return triSum(days) - 42 * triSum(nWeeks - 1) - 6 * nWeeks * rDays