import java.util.*;

class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String key = Arrays.toString(grid[i]);
            map.put(key, map.getOrDefault(key, 0) + 1);
        }
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int[] col = new int[n];
            for (int i = 0; i < n; i++) col[i] = grid[i][j];
            String key = Arrays.toString(col);
            ans += map.getOrDefault(key, 0);
        }
        return ans;
    }

    public boolean closeStrings(String word1, String word2) {
        int[] f1 = new int[26], f2 = new int[26];
        for (char ch : word1.toCharArray()) f1[ch - 'a']++;
        for (char ch : word2.toCharArray()) f2[ch - 'a']++;
        for (int i = 0; i < 26; i++) {
            if ((f1[i] == 0) != (f2[i] == 0)) return false;
        }
        Arrays.sort(f1);
        Arrays.sort(f2);
        for (int i = 0; i < 26; i++) if (f1[i] != f2[i]) return false;
        return true;
    }
}
