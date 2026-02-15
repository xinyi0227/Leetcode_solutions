class Solution {
    private long pack(int w, int v) {
        return ((long) w << 16) | v;
    }

    public int minCost(int n, int[][] edges) {
        List<Long>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();

        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].add(pack(w, v));
            adj[v].add(pack(2 * w, u));
        }

        PriorityQueue<Long> pq = new PriorityQueue<>();
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);

        dist[0] = 0;
        pq.offer(0L);

        while (!pq.isEmpty()) {
            long data = pq.poll();
            int d = (int) (data >> 16);
            int u = (int) (data & 0xFFFF);

            if (d > dist[u]) continue;
            if (u == n - 1) return d;

            for (long wv : adj[u]) {
                int w = (int) (wv >> 16);
                int v = (int) (wv & 0xFFFF);
                int d2 = d + w;

                if (d2 < dist[v]) {
                    dist[v] = d2;
                    pq.offer(pack(d2, v));
                }
            }
        }
        return -1;
    }
}