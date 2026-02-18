class Solution:
    def minimumCost(self, source, target, original, changed, cost):
        inf = float('inf')
        dist = [[inf] * 26 for _ in range(26)]
        
        for i in range(26):
            dist[i][i] = 0
            
        for o, c, w in zip(original, changed, cost):
            u = ord(o) - ord('a')
            v = ord(c) - ord('a')
            dist[u][v] = min(dist[u][v], w)
            
        for k in range(26):
            for i in range(26):
                if dist[i][k] == inf:
                    continue
                for j in range(26):
                    if dist[k][j] != inf:
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
                        
        total_cost = 0
        for s_char, t_char in zip(source, target):
            u = ord(s_char) - ord('a')
            v = ord(t_char) - ord('a')
            if u == v:
                continue
            if dist[u][v] == inf:
                return -1
            total_cost += dist[u][v]
            
        return total_cost