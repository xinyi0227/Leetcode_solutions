class Solution:
    def maxProfit(self, n, present, future, hierarchy, budget):
        tree = [[] for _ in range(n)]
        for edge in hierarchy:
            tree[edge[0]-1].append(edge[1]-1)
        
        dp = [[[0] * (budget + 1) for _ in range(2)] for _ in range(n)]
        self.dfs(0, present, future, tree, dp, budget)
        
        return max(dp[0][0][b] for b in range(budget + 1))
    
    def dfs(self, u, present, future, tree, dp, budget):
        childDPs = []
        for v in tree[u]:
            self.dfs(v, present, future, tree, dp, budget)
            childDPs.append((dp[v][0], dp[v][1]))
        
        for parentBought in range(2):
            price = present[u] // 2 if parentBought else present[u]
            profit = future[u] - price
            
            curr = [0] * (budget + 1)
            
            base = [0] * (budget + 1)
            for child in childDPs:
                next_dp = [0] * (budget + 1)
                for b1 in range(budget + 1):
                    if base[b1] == 0 and b1 != 0: continue
                    for b2 in range(budget - b1 + 1):
                        next_dp[b1 + b2] = max(next_dp[b1 + b2], base[b1] + child[0][b2])
                base = next_dp
            
            for b in range(budget + 1):
                curr[b] = max(curr[b], base[b])
            
            if price <= budget:
                baseBuy = [0] * (budget + 1)
                for child in childDPs:
                    next_dp = [0] * (budget + 1)
                    for b1 in range(budget + 1):
                        if baseBuy[b1] == 0 and b1 != 0: continue
                        for b2 in range(budget - b1 + 1):
                            next_dp[b1 + b2] = max(next_dp[b1 + b2], baseBuy[b1] + child[1][b2])
                    baseBuy = next_dp
                
                for b in range(price, budget + 1):
                    curr[b] = max(curr[b], baseBuy[b - price] + profit)
            
            dp[u][parentBought] = curr