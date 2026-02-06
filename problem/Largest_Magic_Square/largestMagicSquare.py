class Solution(object):
    def largestMagicSquare(self, grid):
        r, c = len(grid), len(grid[0])

        rowSum = [[0] * (c + 1) for _ in range(r)]
        for i in range(r):
            for j in range(c):
                rowSum[i][j+1] = rowSum[i][j] + grid[i][j]

        colSum = [[0] * (r + 1) for _ in range(c)]
        for j in range(c):
            for i in range(r):
                colSum[j][i+1] = colSum[j][i] + grid[i][j]

        diag = [[0] * (c + 1) for _ in range(r + 1)]
        antidiag = [[0] * (c + 1) for _ in range(r + 1)]

        for i in range(r):
            for j in range(c):
                diag[i+1][j+1] = diag[i][j] + grid[i][j]
                antidiag[i+1][j] = antidiag[i][j+1] + grid[i][j]

        def isMagic(k):
            for i in range(r - k + 1):
                for j in range(c - k + 1):
                    Sum = diag[i+k][j+k] - diag[i][j]
                    antiD = antidiag[i+k][j] - antidiag[i][j+k]
                    
                    if Sum != antiD:
                        continue
                    
                    match = True
                    for m in range(k):
                        row_val = rowSum[i+m][j+k] - rowSum[i+m][j]
                        col_val = colSum[j+m][i+k] - colSum[j+m][i]
                        
                        if row_val != Sum or col_val != Sum:
                            match = False
                            break
                    
                    if match:
                        return True
            return False

        for k in range(min(r, c), 1, -1):
            if isMagic(k): 
                return k
        
        return 1