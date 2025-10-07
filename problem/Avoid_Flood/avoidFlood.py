class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size + 1))

    def find(self, i):
        if i == self.parent[i]:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def unite(self, i):
        self.parent[i] = self.find(i + 1)

class Solution:
    def avoidFlood(self, rain):
        n = len(rain)
        uf = UnionFind(n)
        lake_to_day = {}
        res = [1] * n

        for i in range(n):
            lake = rain[i]
            if lake == 0:
                continue

            res[i] = -1
            uf.unite(i)

            if lake in lake_to_day:
                prev = lake_to_day[lake]
                dry = uf.find(prev + 1)

                if dry >= i:
                    return []

                res[dry] = lake
                uf.unite(dry)
                lake_to_day[lake] = i
            else:
                lake_to_day[lake] = i
        
        return res