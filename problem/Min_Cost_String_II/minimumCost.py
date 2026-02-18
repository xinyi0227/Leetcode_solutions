class Solution:
    def minimumCost(self, source, target, original, changed, cost):
        inf = float('inf')
        str_to_id = {}
        lens = set()
        
        def get_id(s):
            if s not in str_to_id:
                str_to_id[s] = len(str_to_id)
            return str_to_id[s]
            
        for s in original:
            lens.add(len(s))
            get_id(s)
        for s in changed:
            get_id(s)
            
        sz = len(str_to_id)
        dist = [[inf] * sz for _ in range(sz)]
        for i in range(sz):
            dist[i][i] = 0
            
        for o, c, z in zip(original, changed, cost):
            u, v = str_to_id[o], str_to_id[c]
            dist[u][v] = min(dist[u][v], z)
            
        for k in range(sz):
            for i in range(sz):
                if dist[i][k] == inf: continue
                for j in range(sz):
                    if dist[i][j] > dist[i][k] + dist[k][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
                        
        n = len(source)
        dp = [inf] * (n + 1)
        dp[0] = 0
        
        for i in range(n):
            if dp[i] == inf: continue
            
            if source[i] == target[i]:
                dp[i+1] = min(dp[i+1], dp[i])
                
            for L in lens:
                if i + L <= n:
                    s_sub = source[i:i+L]
                    t_sub = target[i:i+L]
                    if s_sub in str_to_id and t_sub in str_to_id:
                        d = dist[str_to_id[s_sub]][str_to_id[t_sub]]
                        if d != inf:
                            dp[i+L] = min(dp[i+L], dp[i] + d)
                            
        return int(dp[n]) if dp[n] != inf else -1