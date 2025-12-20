/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} values
 * @param {number} k
 * @return {number}
 */
var maxKDivisibleComponents = function(n, edges, values, k) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const visited = new Array(n).fill(false);
    let ans = 0;
    function dfs(i) {
        visited[i] = true;
        let sum = values[i];
        for (const j of adj[i]) {
            if (visited[j]) continue;
            sum += dfs(j);
            sum %= k;
        }
        if (sum % k === 0) {
            ans++;
            return 0;
        }
        return sum;
    }
    dfs(0);
    return ans;
};
