class Solution {
    public int largestMagicSquare(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;

        int[][] rowSum = new int[r][c + 1];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
            }
        }

        int[][] colSum = new int[c][r + 1];
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                colSum[j][i + 1] = colSum[j][i] + grid[i][j];
            }
        }

        int[][] diag = new int[r + 1][c + 1];
        int[][] antidiag = new int[r + 1][c + 1];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                antidiag[i + 1][j] = antidiag[i][j + 1] + grid[i][j];
            }
        }

        for (int k = Math.min(r, c); k > 1; k--) {
            for (int i = 0; i <= r - k; i++) {
                for (int j = 0; j <= c - k; j++) {
                    int sum = diag[i + k][j + k] - diag[i][j];
                    int antiSum = antidiag[i + k][j] - antidiag[i][j + k];

                    if (sum != antiSum) continue;

                    boolean match = true;
                    for (int m = 0; m < k; m++) {
                        int rSum = rowSum[i + m][j + k] - rowSum[i + m][j];
                        int cSum = colSum[j + m][i + k] - colSum[j + m][i];
                        if (rSum != sum || cSum != sum) {
                            match = false;
                            break;
                        }
                    }

                    if (match) return k;
                }
            }
        }

        return 1;
    }
}