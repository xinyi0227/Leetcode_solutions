class Solution:
    def longestBalanced(self, nums):
        class SegTree:
            def __init__(self, n):
                self.n = n
                self.sum = [0] * (4 * n + 5)
                self.mn = [0] * (4 * n + 5)
                self.mx = [0] * (4 * n + 5)
                self.lazyVal = [0] * (4 * n + 5)
                self.hasLazy = [False] * (4 * n + 5)

            def pull(self, v):
                self.sum[v] = self.sum[v << 1] + self.sum[v << 1 | 1]
                self.mn[v] = min(self.mn[v << 1], self.sum[v << 1] + self.mn[v << 1 | 1])
                self.mx[v] = max(self.mx[v << 1], self.sum[v << 1] + self.mx[v << 1 | 1])

            def applySet(self, v, l, r, val):
                length = r - l + 1
                self.sum[v] = val * length
                if val == 0:
                    self.mn[v] = 0
                    self.mx[v] = 0
                elif val > 0:
                    self.mn[v] = val
                    self.mx[v] = val * length
                else:
                    self.mn[v] = val * length
                    self.mx[v] = val
                self.hasLazy[v] = True
                self.lazyVal[v] = val

            def push(self, v, l, r):
                if not self.hasLazy[v] or l == r:
                    return
                m = (l + r) >> 1
                self.applySet(v << 1, l, m, self.lazyVal[v])
                self.applySet(v << 1 | 1, m + 1, r, self.lazyVal[v])
                self.hasLazy[v] = False

            def updatePos(self, pos, newval):
                self.update(1, 0, self.n - 1, pos, pos, newval)

            def update(self, v, l, r, ql, qr, val):
                if ql <= l and r <= qr:
                    self.applySet(v, l, r, val)
                    return
                self.push(v, l, r)
                m = (l + r) >> 1
                if ql <= m:
                    self.update(v << 1, l, m, ql, qr, val)
                if qr > m:
                    self.update(v << 1 | 1, m + 1, r, ql, qr, val)
                self.pull(v)

            def query(self, x):
                if x == 0: return -1
                if x < self.mn[1] or x > self.mx[1]: return self.n
                pref = [0]
                return self.queryRec(1, 0, self.n - 1, x, pref)

            def queryRec(self, v, l, r, x, pref):
                if l == r:
                    if pref[0] + self.sum[v] == x: return l
                    return self.n
                self.push(v, l, r)
                m = (l + r) >> 1
                L = v << 1
                R = v << 1 | 1
                
                leftMin = pref[0] + self.mn[L]
                leftMax = pref[0] + self.mx[L]
                
                if x >= leftMin and x <= leftMax:
                    return self.queryRec(L, l, m, x, pref)
                else:
                    pref[0] += self.sum[L]
                    return self.queryRec(R, m + 1, r, x, pref)

        n = len(nums)
        if n == 0: return 0
        m_val = max(nums)
        lastPos = [-1] * (m_val + 1)
        S = SegTree(n)
        
        current_sum = 0
        ans = 0
        
        for i in range(n):
            if lastPos[nums[i]] != -1:
                S.updatePos(lastPos[nums[i]], 0)
            else:
                if nums[i] % 2 != 0: current_sum += 1
                else: current_sum -= 1
            
            lastPos[nums[i]] = i
            
            if nums[i] % 2 != 0: S.updatePos(i, 1)
            else: S.updatePos(i, -1)
            
            p = S.query(current_sum)
            ans = max(ans, i - p)
            
        return ans