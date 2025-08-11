class Solution:
    def productQueries(self, n, queries):
        MOD = 1000000007
        
        def modPow(base, exp, mod):
            result = 1
            while exp > 0:
                if exp & 1:
                    result = (result * base) % mod
                base = (base * base) % mod
                exp >>= 1
            return result
        
        p = [0]
        for i in range(31):
            if n >> i & 1:
                p.append(p[-1] + i)
        
        res = []
        for l, r in queries:
            res.append(modPow(2, p[r + 1] - p[l], MOD))
        
        return res
