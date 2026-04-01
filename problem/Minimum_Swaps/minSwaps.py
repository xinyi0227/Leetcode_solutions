class Solution:
    def minSwaps(self, grid):
        n = len(grid)
        trailing_zeros = []
        for row in grid:
            count = 0
            for i in range(n - 1, -1, -1):
                if row[i] == 0:
                    count += 1
                else:
                    break
            trailing_zeros.append(count)
        
        swaps = 0
        for i in range(n):
            target = n - 1 - i
            found = -1
            for j in range(i, n):
                if trailing_zeros[j] >= target:
                    found = j
                    break
            
            if found == -1:
                return -1
            
            swaps += (found - i)
            val = trailing_zeros.pop(found)
            trailing_zeros.insert(i, val)
            
        return swaps