class Solution:
    def gcd(self, a, b):
        while b:
            a %= b
            a, b = b, a
        return a

    def countTriples(self, n):
        cnt = 0
        m = 2
        while m * m < n:
            for k in range(1, m):
                if self.gcd(m, k) == 1 and (m - k) % 2 == 1:
                    c = m * m + k * k
                    if c > n:
                        break
                    cnt += 2 * (n // c)
            m += 1
        return cnt
