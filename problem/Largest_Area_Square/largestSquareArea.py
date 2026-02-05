class Solution:
    def largestSquareArea(self, bottomLeft, topRight):
        rects = []
        n = len(bottomLeft)
        for i in range(n):
            rects.append((bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]))
            
        rects.sort()
        
        max_side = 0
        
        for r in range(1, n):
            a, b, c, d = rects[r]
            for l in range(r):
                _, bj, cj, dj = rects[l]
                
                width = min(cj, c) - a
                height = min(dj, d) - max(bj, b)
                s = min(width, height)
                
                if s > max_side:
                    max_side = s
                    
        return max_side * max_side