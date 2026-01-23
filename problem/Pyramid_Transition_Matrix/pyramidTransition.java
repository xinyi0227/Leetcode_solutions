import java.util.*;

class Solution {
    private int[] pattern = new int[36];
    private boolean[][] bad = new boolean[8][117649];

    private int encode(char[] s, int len) {
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans = ans * 7 + (s[i] - 'A');
        }
        return ans;
    }

    private boolean check(char[] cur, int sz) {
        for (int i = 0; i < sz - 1; i++) {
            if (cur[i] == 'G') return false;
            int key = (cur[i] - 'A') * 6 + (cur[i + 1] - 'A');
            if (pattern[key] == 0) return false;
        }
        return true;
    }

    private void addPattern(List<String> allowed) {
        Arrays.fill(pattern, 0);
        for (String s : allowed) {
            int idx = (s.charAt(0) - 'A') * 6 + (s.charAt(1) - 'A');
            pattern[idx] |= 1 << (s.charAt(2) - 'A');
        }
    }

    private boolean dfs(char[] cur, char[] next, int i, int sz) {
        if (i == sz - 1) {
            if (sz == 2) return true;
            if (!check(next, sz - 1)) return false;

            int idx = encode(next, sz - 1);
            if (bad[sz - 1][idx]) return false;

            char[] up = new char[sz - 1];
            Arrays.fill(up, 'G');
            
            if (!dfs(next, up, 0, sz - 1)) {
                bad[sz - 1][idx] = true;
                return false;
            }
            return true;
        }

        int key = (cur[i] - 'A') * 6 + (cur[i + 1] - 'A');
        int mask = pattern[key];

        while (mask != 0) {
            int bit = mask & -mask;
            mask -= bit;

            int c = Integer.numberOfTrailingZeros(bit);
            next[i] = (char) ('A' + c);

            if (dfs(cur, next, i + 1, sz)) return true;
        }
        return false;
    }

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for (int i = 0; i < 8; i++) {
            Arrays.fill(bad[i], false);
        }
        addPattern(allowed);

        char[] cur = bottom.toCharArray();
        char[] next = new char[bottom.length() - 1];
        Arrays.fill(next, 'G');

        return dfs(cur, next, 0, bottom.length());
    }
}