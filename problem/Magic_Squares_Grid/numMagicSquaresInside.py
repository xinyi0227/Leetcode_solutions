class Solution:
    def numMagicSquaresInside(self, grid):
        def isValid(i, j, grid):
            count = [0] * 10
            for x in range(3):
                for y in range(3):
                    num = grid[i + x][j + y]
                    if num < 1 or num > 9 or count[num] > 0:
                        return False
                    count[num] += 1
            
            s = grid[i][j] + grid[i][j+1] + grid[i][j+2]
            
            for x in range(3):
                if s != (grid[i + x][j] + grid[i + x][j + 1] + grid[i + x][j + 2]):
                    return False
            
            for y in range(3):
                if s != (grid[i][j + y] + grid[i + 1][j + y] + grid[i + 2][j + y]):
                    return False
            
            if s != (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]):
                return False
            if s != (grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2]):
                return False
                
            return True

        cnt = 0
        row = len(grid)
        col = len(grid[0])
        
        if row < 3 or col < 3:
            return 0
            
        for i in range(row - 2):
            for j in range(col - 2):
                if isValid(i, j, grid):
                    cnt += 1
                    
        return cnt