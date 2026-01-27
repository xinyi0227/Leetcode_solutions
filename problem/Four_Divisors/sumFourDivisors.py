import math

class Solution(object):
    def sumFourDivisors(self, nums):
        res = 0
        for n in nums:
            val = self.sumOne(n)
            if val != -1:
                res += val
        return res

    def sumOne(self, n):
        p = int(round(n ** (1.0 / 3.0)))
        if p * p * p == n and self.isPrime(p):
            return 1 + p + p * p + p * p * p

        limit = int(math.sqrt(n))
        for i in range(2, limit + 1):
            if n % i == 0:
                a = i
                b = n // i
                if a != b and self.isPrime(a) and self.isPrime(b):
                    return 1 + a + b + n
                return -1
        return -1

    def isPrime(self, x):
        if x < 2:
            return False
        limit = int(math.sqrt(x))
        for i in range(2, limit + 1):
            if x % i == 0:
                return False
        return True