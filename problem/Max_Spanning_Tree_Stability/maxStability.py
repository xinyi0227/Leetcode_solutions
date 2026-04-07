class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.components = n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def unite(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a == root_b:
            return False
        if self.rank[root_a] < self.rank[root_b]:
            root_a, root_b = root_b, root_a
        self.parent[root_b] = root_a
        if self.rank[root_a] == self.rank[root_b]:
            self.rank[root_a] += 1
        self.components -= 1
        return True

class Solution:
    def maxStability(self, n, edges, k):
        def can_achieve(x):
            dsu = DSU(n)
            for u, v, s, must in edges:
                if must == 1:
                    if s < x or not dsu.unite(u, v):
                        return False
            for u, v, s, must in edges:
                if must == 0 and s >= x:
                    dsu.unite(u, v)
            used_upgrades = 0
            for u, v, s, must in edges:
                if must == 0 and s < x and 2 * s >= x:
                    if dsu.unite(u, v):
                        used_upgrades += 1
            return dsu.components == 1 and used_upgrades <= k

        initial_dsu = DSU(n)
        for u, v, s, must in edges:
            if must == 1 and not initial_dsu.unite(u, v):
                return -1

        low, high, ans = 1, 200000, -1
        while low <= high:
            mid = (low + high) // 2
            if can_achieve(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        return ans