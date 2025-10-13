class Solution:
    def magicalSum(self, m, k, nums):
        MOD = 10**9 + 7
        n = len(nums)
        C = [[0]*(m+1) for _ in range(m+1)]
        for i in range(m+1):
            C[i][0] = 1
            C[i][i] = 1
            for j in range(1, i):
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD
        powA = [[1]*(m+1) for _ in range(n)]
        for i, a in enumerate(nums):
            a %= MOD
            for t in range(1, m+1):
                powA[i][t] = (powA[i][t-1] * a) % MOD
        M = m
        size = M + 1
        cur = [0] * (size * size * size)
        def idx(r, c, o): return ((r * size) + c) * size + o
        cur[idx(M, 0, 0)] = 1
        for i in range(n):
            nxt = [0] * (size * size * size)
            for r in range(M+1):
                for carry in range(M+1):
                    base = ((r * size) + carry) * size
                    for ones in range(M+1):
                        val = cur[base + ones]
                        if not val: 
                            continue
                        for t in range(r+1):
                            newr = r - t
                            s = carry + t
                            bit = s & 1
                            newones = ones + bit
                            if newones > M:
                                continue
                            newcarry = s >> 1
                            mult = (C[r][t] * powA[i][t]) % MOD
                            add = (val * mult) % MOD
                            j = idx(newr, newcarry, newones)
                            x = nxt[j] + add
                            if x >= MOD: x -= MOD
                            nxt[j] = x
            cur = nxt
        ans = 0
        base0 = 0
        for carry in range(M+1):
            for ones in range(M+1):
                val = cur[base0 + carry * size + ones]
                if not val:
                    continue
                extra = bin(carry).count("1")
                if ones + extra == k:
                    ans = (ans + val) % MOD
        return ans