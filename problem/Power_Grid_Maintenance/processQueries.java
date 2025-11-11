import java.util.*;

class Solution {
    int[] parent, size, offline;
    Map<Integer, PriorityQueue<Integer>> mp;

    int findParent(int x) {
        if (parent[x] == x) return x;
        parent[x] = findParent(parent[x]);
        return parent[x];
    }

    void Union(int u, int v) {
        int up = findParent(u), vp = findParent(v);
        if (up == vp) return;
        if (size[up] > size[vp]) {
            size[up] += size[vp];
            parent[vp] = up;
            PriorityQueue<Integer> a = mp.get(up), b = mp.get(vp);
            while (!b.isEmpty()) a.offer(b.poll());
        } else {
            size[vp] += size[up];
            parent[up] = vp;
            PriorityQueue<Integer> a = mp.get(vp), b = mp.get(up);
            while (!b.isEmpty()) a.offer(b.poll());
        }
    }

    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        parent = new int[c];
        size = new int[c];
        offline = new int[c];
        mp = new HashMap<>();
        for (int i = 0; i < c; i++) {
            parent[i] = i;
            size[i] = 1;
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            pq.offer(i);
            mp.put(i, pq);
        }
        for (int[] e : connections) {
            int u = e[0] - 1, v = e[1] - 1;
            Union(u, v);
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int[] q : queries) {
            int type = q[0];
            int node = q[1] - 1;
            if (type == 1) {
                if (offline[node] == 0) {
                    ans.add(node + 1);
                    continue;
                }
                int p = findParent(node);
                PriorityQueue<Integer> pq = mp.get(p);
                while (!pq.isEmpty() && offline[pq.peek()] == 1) pq.poll();
                if (pq.isEmpty()) ans.add(-1);
                else ans.add(pq.peek() + 1);
            } else {
                offline[node] = 1;
            }
        }
        int[] out = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) out[i] = ans.get(i);
        return out;
    }
}