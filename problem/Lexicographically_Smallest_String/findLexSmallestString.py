class Solution:
    def findLexSmallestString(self, s, a, b):
        from collections import deque
        vis = set()
        smallest = s
        q = deque([s])
        vis.add(s)
        while q:
            cur = q.popleft()
            if cur < smallest:
                smallest = cur
            added = list(cur)
            for i in range(1, len(added), 2):
                added[i] = str((int(added[i]) + a) % 10)
            added = ''.join(added)
            if added not in vis:
                vis.add(added)
                q.append(added)
            rotated = cur[-b:] + cur[:-b]
            if rotated not in vis:
                vis.add(rotated)
                q.append(rotated)
        return smallest