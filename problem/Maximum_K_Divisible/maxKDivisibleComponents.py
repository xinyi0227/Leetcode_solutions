class Solution:
    def maxKDivisibleComponents(self, n, edges, values, k):
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        visited = [False] * n
        self.ans = 0

        def dfs(i):
            visited[i] = True
            s = values[i]
            for j in adj[i]:
                if visited[j]:
                    continue
                s += dfs(j)
                s %= k
            if s % k == 0:
                self.ans += 1
                return 0
            return s

        dfs(0)
        return self.ans
