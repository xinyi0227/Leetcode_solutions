import java.util.*;

class Solution {
    public int[][] minAbsDiff(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] ans = new int[m - k + 1][n - k + 1];

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                List<Integer> v = new ArrayList<>();
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        v.add(grid[x][y]);
                    }
                }

                Collections.sort(v);
                
                List<Integer> uniqueV = new ArrayList<>();
                if (!v.isEmpty()) {
                    uniqueV.add(v.get(0));
                    for (int p = 1; p < v.size(); p++) {
                        if (!v.get(p).equals(v.get(p - 1))) {
                            uniqueV.add(v.get(p));
                        }
                    }
                }

                if (uniqueV.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int mn = Integer.MAX_VALUE;
                    for (int p = 0; p < uniqueV.size() - 1; p++) {
                        mn = Math.min(mn, uniqueV.get(p + 1) - uniqueV.get(p));
                    }
                    ans[i][j] = mn;
                }
            }
        }
        return ans;
    }
}