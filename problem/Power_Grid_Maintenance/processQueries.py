import heapq

class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1]*n
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    def union(self, a, b):
        a = self.find(a); b = self.find(b)
        if a == b: return a
        if self.sz[a] > self.sz[b]:
            self.sz[a] += self.sz[b]
            self.p[b] = a
            return a, b
        else:
            self.sz[b] += self.sz[a]
            self.p[a] = b
            return b, a

class Solution:
    def processQueries(self, c, connections, queries):
        dsu = DSU(c)
        heaps = [ [i] for i in range(c) ]
        for h in heaps:
            heapq.heapify(h)
        offline = [0]*c

        for u, v in connections:
            u -= 1; v -= 1
            ru = dsu.find(u); rv = dsu.find(v)
            if ru != rv:
                to, from_ = dsu.union(ru, rv)
                if isinstance(to, tuple):
                    to, from_ = to
                # merge from_ into to
                if dsu.find(from_) != to:
                    to = dsu.find(to); from_ = dsu.find(from_)
                # ensure indices consistent
                if heaps[from_] is not heaps[to]:
                    for x in heaps[from_]:
                        heapq.heappush(heaps[to], x)
                    heaps[from_] = heaps[to]

        ans = []
        for t, node in queries:
            node -= 1
            if t == 1:
                if offline[node] == 0:
                    ans.append(node+1)
                    continue
                p = dsu.find(node)
                h = heaps[p]
                while h and offline[h[0]] == 1:
                    heapq.heappop(h)
                ans.append(-1 if not h else h[0]+1)
            else:
                offline[node] = 1
        return ans