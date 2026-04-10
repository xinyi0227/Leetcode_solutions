import java.util.*;

class Solution {
    public int[] getBiggestThree(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] diag1 = new int[m + 1][n + 1];
        int[][] diag2 = new int[m + 1][n + 2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        TreeSet<Integer> top3 = new TreeSet<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                top3.add(grid[i][j]);
                if (top3.size() > 3) top3.pollFirst();

                for (int k = 1; i - k >= 0 && i + k < m && j - k >= 0 && j + k < n; k++) {
                    int topR = i - k, topC = j;
                    int rightR = i, rightC = j + k;
                    int bottomR = i + k, bottomC = j;
                    int leftR = i, leftC = j - k;

                    int border = 0;
                    border += diag1[rightR + 1][rightC + 1] - diag1[topR][topC];
                    border += diag2[bottomR + 1][bottomC] - diag2[rightR][rightC + 1];
                    border += diag1[bottomR + 1][bottomC + 1] - diag1[leftR][leftC];
                    border += diag2[leftR + 1][leftC] - diag2[topR][topC + 1];
                    border -= (grid[topR][topC] + grid[rightR][rightC] + grid[bottomR][bottomC] + grid[leftR][leftC]);

                    top3.add(border);
                    if (top3.size() > 3) top3.pollFirst();
                }
            }
        }

        int[] res = new int[top3.size()];
        for (int i = res.length - 1; i >= 0; i--) {
            res[i] = top3.pollFirst();
        }
        return res;
    }
}