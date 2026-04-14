class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        
        for (int k = 0; k < 4; k++) {
            if (isEqual(mat, target, n)) {
                return true;
            }
            rotate(mat, n);
        }
        
        return false;
    }
    
    private boolean isEqual(int[][] mat, int[][] target, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private void rotate(int[][] mat, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        
        for (int i = 0; i < n / 2; i++) {
            int[] tempRow = mat[i];
            mat[i] = mat[n - 1 - i];
            mat[n - 1 - i] = tempRow;
        }
    }
}