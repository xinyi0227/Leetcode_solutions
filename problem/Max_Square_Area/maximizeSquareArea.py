class Solution:
    def maximizeSquareArea(self, m, n, hFences, vFences):
        hFences.extend([1, m])
        vFences.extend([1, n])
        
        hFences.sort()
        vFences.sort()
        
        hGaps = set()
        for i in range(len(hFences)):
            for j in range(i + 1, len(hFences)):
                hGaps.add(hFences[j] - hFences[i])
        
        maxSide = -1
        for i in range(len(vFences)):
            for j in range(i + 1, len(vFences)):
                currentGap = vFences[j] - vFences[i]
                if currentGap in hGaps:
                    maxSide = max(maxSide, currentGap)
        
        if maxSide == -1:
            return -1
            
        return (maxSide * maxSide) % (10**9 + 7)