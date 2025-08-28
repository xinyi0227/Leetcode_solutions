class Solution:
    def sortMatrix(self, grid):
        import heapq
        
        n = len(grid)
        m = len(grid[0])
        maxHeaps = {}
        minHeaps = {}
        
        for i in range(n):
            for j in range(m):
                key = i - j
                if key < 0:
                    if key not in minHeaps:
                        minHeaps[key] = []
                    heapq.heappush(minHeaps[key], grid[i][j])
                else:
                    if key not in maxHeaps:
                        maxHeaps[key] = []
                    heapq.heappush(maxHeaps[key], -grid[i][j])
        
        for i in range(n):
            for j in range(m):
                key = i - j
                if key < 0:
                    grid[i][j] = heapq.heappop(minHeaps[key])
                else:
                    grid[i][j] = -heapq.heappop(maxHeaps[key])
        
        return grid
