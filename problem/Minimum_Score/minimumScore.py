from collections import defaultdict, deque

class Solution:
    def minimumScore(self, nums, edges):
        n = len(nums)
        m = len(edges)
        
        graph = defaultdict(list)
        children = defaultdict(set)
        arr = nums[:]
        degree = [0]*n
        
        for x, y in edges:
            graph[x].append(y)
            graph[y].append(x)
            degree[x] += 1
            degree[y] += 1
        
        v = 0
        seen = set()
        q = deque()
        for i in range(n):
            v ^= nums[i]
            if degree[i] == 1:
                q.append(i)
                seen.add(i)
        
        while q:
            curr = q.popleft()
            for nxt in graph[curr]:
                if nxt not in seen:
                    children[nxt].add(curr)
                    children[nxt] |= children[curr]
                    arr[nxt] ^= arr[curr]
                degree[nxt] -= 1
                if degree[nxt] == 1:
                    seen.add(nxt)
                    q.append(nxt)
        
        ans = float('inf')
        for i in range(m-1):
            for j in range(i+1, m):
                a, b = edges[i]
                if b in children[a]:
                    a, b = b, a
                c, d = edges[j]
                if d in children[c]:
                    c, d = d, c
                
                if c in children[a]:
                    curr = [arr[c], arr[c]^arr[a], v^arr[a]]
                elif a in children[c]:
                    curr = [arr[a], arr[c]^arr[a], v^arr[c]]
                else:
                    curr = [arr[a], arr[c], v^arr[a]^arr[c]]
                ans = min(ans, max(curr)-min(curr))
        return ans
