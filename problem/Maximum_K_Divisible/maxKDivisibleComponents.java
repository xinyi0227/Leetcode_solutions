class Solution {
    int ans = 0;
    List<Integer>[] adj;
    boolean[] visited;

    long dfs(int i, int[] values, int k) {
        visited[i] = true;
        long sum = values[i];
        for (int j : adj[i]) {
            if (visited[j]) continue;
            sum += dfs(j, values, k);
            sum %= k;
        }
        if (sum % k == 0) {
            ans++;
            return 0;
        }
        return sum;
    }

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            adj[u].add(v);
            adj[v].add(u);
        }
        visited = new boolean[n];
        dfs(0, values, k);
        return ans;
    }
}
