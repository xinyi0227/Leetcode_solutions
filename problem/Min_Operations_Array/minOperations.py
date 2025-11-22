class Solution:
    def minOperations(self, nums):
        def my_gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        n = len(nums)
        ones = nums.count(1)
        if ones:
            return n - ones

        INF = 10**18
        res = INF

        for i in range(n):
            g = nums[i]
            for j in range(i + 1, n):
                g = my_gcd(g, nums[j])
                if g == 1:
                    res = min(res, j - i)
                    break

        if res == INF:
            return -1
        return res + n - 1