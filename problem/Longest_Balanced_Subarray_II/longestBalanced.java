class Solution {
    class SegTree {
        int n;
        int[] sum, mn, mx, lazyVal;
        boolean[] hasLazy;

        public SegTree(int _n) {
            n = _n;
            sum = new int[4 * n + 5];
            mn = new int[4 * n + 5];
            mx = new int[4 * n + 5];
            lazyVal = new int[4 * n + 5];
            hasLazy = new boolean[4 * n + 5];
        }

        void pull(int v) {
            sum[v] = sum[v << 1] + sum[v << 1 | 1];
            mn[v] = Math.min(mn[v << 1], sum[v << 1] + mn[v << 1 | 1]);
            mx[v] = Math.max(mx[v << 1], sum[v << 1] + mx[v << 1 | 1]);
        }

        void applySet(int v, int l, int r, int val) {
            int len = r - l + 1;
            sum[v] = val * len;
            if (val == 0) {
                mn[v] = 0;
                mx[v] = 0;
            } else if (val > 0) {
                mn[v] = val;
                mx[v] = val * len;
            } else {
                mn[v] = val * len;
                mx[v] = val;
            }
            hasLazy[v] = true;
            lazyVal[v] = val;
        }

        void push(int v, int l, int r) {
            if (!hasLazy[v] || l == r) return;
            int m = (l + r) >> 1;
            applySet(v << 1, l, m, lazyVal[v]);
            applySet(v << 1 | 1, m + 1, r, lazyVal[v]);
            hasLazy[v] = false;
        }

        void update(int pos, int newval) {
            update(1, 0, n - 1, pos, pos, newval);
        }

        void update(int v, int l, int r, int ql, int qr, int val) {
            if (ql <= l && r <= qr) {
                applySet(v, l, r, val);
                return;
            }
            push(v, l, r);
            int m = (l + r) >> 1;
            if (ql <= m) update(v << 1, l, m, ql, qr, val);
            if (qr > m) update(v << 1 | 1, m + 1, r, ql, qr, val);
            pull(v);
        }

        int query(int x) {
            if (x == 0) return -1;
            if (x < mn[1] || x > mx[1]) return n;
            int[] pref = {0};
            return query(1, 0, n - 1, x, pref);
        }

        int query(int v, int l, int r, int x, int[] pref) {
            if (l == r) {
                if (pref[0] + sum[v] == x) return l;
                return n;
            }
            push(v, l, r);
            int m = (l + r) >> 1;
            int L = v << 1;
            int R = v << 1 | 1;

            int leftMin = pref[0] + mn[L];
            int leftMax = pref[0] + mx[L];

            if (x >= leftMin && x <= leftMax) {
                return query(L, l, m, x, pref);
            } else {
                pref[0] += sum[L];
                return query(R, m + 1, r, x, pref);
            }
        }
    }

    public int longestBalanced(int[] nums) {
        int n = nums.length;
        int m = 0;
        for (int x : nums) m = Math.max(m, x);
        
        int[] lastPos = new int[m + 1];
        java.util.Arrays.fill(lastPos, -1);
        
        SegTree S = new SegTree(n);
        int sum = 0;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (lastPos[nums[i]] != -1) {
                S.update(lastPos[nums[i]], 0);
            } else {
                if (nums[i] % 2 != 0) sum++;
                else sum--;
            }
            
            lastPos[nums[i]] = i;
            
            if (nums[i] % 2 != 0) S.update(i, 1);
            else S.update(i, -1);
            
            int p = S.query(sum);
            ans = Math.max(ans, i - p);
        }
        
        return ans;
    }
}