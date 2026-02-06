class Solution:
    def maxSideLength(self, mat, threshold):
        m, n = len(mat), len(mat[0])
        pref = [[0] * (n + 1) for _ in range(m + 1)]
        
        for row in range(1, m + 1):
            for col in range(1, n + 1):
                pref[row][col] = mat[row-1][col-1] + pref[row-1][col] + pref[row][col-1] - pref[row-1][col-1]
                
        max_len = 0
        
        for row in range(1, m + 1):
            for col in range(1, n + 1):
                current_len = max_len + 1
                
                if row >= current_len and col >= current_len:
                    r1 = row - current_len + 1
                    c1 = col - current_len + 1
                    
                    square_sum = pref[row][col] - pref[r1-1][col] - pref[row][c1-1] + pref[r1-1][c1-1]
                    
                    if square_sum <= threshold:
                        max_len += 1
                        
        return max_len