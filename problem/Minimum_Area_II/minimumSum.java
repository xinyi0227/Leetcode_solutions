class Solution {
    public int minimumSum(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] A = new int[n];
        int[] T = new int[m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                A[i] |= (1 << j);
                T[j] |= (1 << i);
            }
        }
        
        int ans = Integer.MAX_VALUE;
        
        for (int c1 = 0; c1 < m - 2; c1++) {
            for (int c2 = c1 + 1; c2 < m - 1; c2++) {
                int a = minRect(A, T, 0, n - 1, 0, c1);
                int b = minRect(A, T, 0, n - 1, c1 + 1, c2);
                int c = minRect(A, T, 0, n - 1, c2 + 1, m - 1);
                ans = Math.min(ans, a + b + c);
            }
        }
        
        for (int r1 = 0; r1 < n - 2; r1++) {
            for (int r2 = r1 + 1; r2 < n - 1; r2++) {
                int a = minRect(A, T, 0, r1, 0, m - 1);
                int b = minRect(A, T, r1 + 1, r2, 0, m - 1);
                int c = minRect(A, T, r2 + 1, n - 1, 0, m - 1);
                ans = Math.min(ans, a + b + c);
            }
        }
        
        for (int r = 0; r < n - 1; r++) {
            for (int c = 0; c < m - 1; c++) {
                int top = minRect(A, T, 0, r, 0, m - 1);
                int bl = minRect(A, T, r + 1, n - 1, 0, c);
                int br = minRect(A, T, r + 1, n - 1, c + 1, m - 1);
                ans = Math.min(ans, top + bl + br);
                
                int bottom = minRect(A, T, r + 1, n - 1, 0, m - 1);
                int tl = minRect(A, T, 0, r, 0, c);
                int tr = minRect(A, T, 0, r, c + 1, m - 1);
                ans = Math.min(ans, bottom + tl + tr);
                
                int left = minRect(A, T, 0, n - 1, 0, c);
                tr = minRect(A, T, 0, r, c + 1, m - 1);
                br = minRect(A, T, r + 1, n - 1, c + 1, m - 1);
                ans = Math.min(ans, left + tr + br);
                
                int right = minRect(A, T, 0, n - 1, c + 1, m - 1);
                tl = minRect(A, T, 0, r, 0, c);
                bl = minRect(A, T, r + 1, n - 1, 0, c);
                ans = Math.min(ans, right + tl + bl);
            }
        }
        
        return ans;
    }
    
    private int minRect(int[] A, int[] T, int i0, int iN, int j0, int jN) {
        int iMin = 30, iMax = -1, jMin = 30, jMax = -1;
        for (int i = i0; i <= iN; i++) {
            int row = A[i];
            int mRow = (row >> j0) << j0;
            mRow &= ((1 << (jN + 1)) - 1);
            if (mRow != 0) {
                iMin = i;
                break;
            }
        }
        if (iMin == 30) return (int)1e8;
        for (int i = iN; i >= iMin; i--) {
            int row = A[i];
            int mRow = (row >> j0) << j0;
            mRow &= ((1 << (jN + 1)) - 1);
            if (mRow != 0) {
                iMax = i;
                break;
            }
        }
        for (int j = j0; j <= jN; j++) {
            int col = T[j];
            int mCol = (col >> i0) << i0;
            mCol &= ((1 << (iN + 1)) - 1);
            if (mCol != 0) {
                jMin = j;
                break;
            }
        }
        for (int j = jN; j >= jMin; j--) {
            int col = T[j];
            int mCol = (col >> i0) << i0;
            mCol &= ((1 << (iN + 1)) - 1);
            if (mCol != 0) {
                jMax = j;
                break;
            }
        }
        return (iMax - iMin + 1) * (jMax - jMin + 1);
    }
}
