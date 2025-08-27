class Solution:
    def areaOfMaxDiagonal(self, dimensions):
        maxArea = 0
        maxDiag = 0
        
        for i in range(len(dimensions)):
            l = dimensions[i][0]
            w = dimensions[i][1]
            currDiag = l * l + w * w
            
            if currDiag > maxDiag or (currDiag == maxDiag and l * w > maxArea):
                maxDiag = currDiag
                maxArea = l * w
        
        return maxArea
