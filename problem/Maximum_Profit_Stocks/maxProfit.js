/**
 * @param {number} n
 * @param {number[]} present
 * @param {number[]} future
 * @param {number[][]} hierarchy
 * @param {number} budget
 * @return {number}
 */
var maxProfit = function(n, present, future, hierarchy, budget) {
    let tree = Array(n).fill().map(() => []);
    for (let edge of hierarchy) {
        tree[edge[0]-1].push(edge[1]-1);
    }
    
    let dp = Array(n).fill().map(() => [[0].concat(Array(budget).fill(0)), [0].concat(Array(budget).fill(0))]);
    dfs(0, present, future, tree, dp, budget);
    
    let ans = 0;
    for (let b = 0; b <= budget; ++b) {
        ans = Math.max(ans, dp[0][0][b]);
    }
    return ans;
    
    function dfs(u, present, future, tree, dp, budget) {
        let childDPs = [];
        for (let v of tree[u]) {
            dfs(v, present, future, tree, dp, budget);
            childDPs.push([dp[v][0], dp[v][1]]);
        }
        
        for (let parentBought = 0; parentBought <= 1; ++parentBought) {
            let price = parentBought ? Math.floor(present[u] / 2) : present[u];
            let profit = future[u] - price;
            
            let curr = Array(budget + 1).fill(0);
            
            let base = Array(budget + 1).fill(0);
            for (let child of childDPs) {
                let next_dp = Array(budget + 1).fill(0);
                for (let b1 = 0; b1 <= budget; ++b1) {
                    if (base[b1] === 0 && b1 !== 0) continue;
                    for (let b2 = 0; b1 + b2 <= budget; ++b2) {
                        next_dp[b1 + b2] = Math.max(next_dp[b1 + b2], base[b1] + child[0][b2]);
                    }
                }
                base = next_dp;
            }
            
            for (let b = 0; b <= budget; ++b) {
                curr[b] = Math.max(curr[b], base[b]);
            }
            
            if (price <= budget) {
                let baseBuy = Array(budget + 1).fill(0);
                for (let child of childDPs) {
                    let next_dp = Array(budget + 1).fill(0);
                    for (let b1 = 0; b1 <= budget; ++b1) {
                        if (baseBuy[b1] === 0 && b1 !== 0) continue;
                        for (let b2 = 0; b1 + b2 <= budget; ++b2) {
                            next_dp[b1 + b2] = Math.max(next_dp[b1 + b2], baseBuy[b1] + child[1][b2]);
                        }
                    }
                    baseBuy = next_dp;
                }
                
                for (let b = price; b <= budget; ++b) {
                    curr[b] = Math.max(curr[b], baseBuy[b - price] + profit);
                }
            }
            
            dp[u][parentBought] = curr;
        }
    }
};