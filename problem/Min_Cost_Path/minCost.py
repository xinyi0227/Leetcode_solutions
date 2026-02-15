class Solution:
    def minCost(self, n, edges):
        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((w, v))
            adj[v].append((2 * w, u))
            
        pq = [(0, 0)] 
        dist = [float('inf')] * n
        dist[0] = 0
        
        while pq:
            d, u = heapq.heappop(pq)
            
            if d > dist[u]:
                continue
            if u == n - 1:
                return d
            
            for w, v in adj[u]:
                d2 = d + w
                if d2 < dist[v]:
                    dist[v] = d2
                    heapq.heappush(pq, (d2, v))
                    
        return -1