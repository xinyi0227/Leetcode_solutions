import heapq

class Solution:
    def minimumPairRemoval(self, nums):
        n = len(nums)
        if n <= 1:
            return 0
        
        arr = [float(x) for x in nums]
        removed = [False] * n
        pq = []
        
        sorted_count = 0
        for i in range(1, n):
            heapq.heappush(pq, (arr[i-1] + arr[i], i-1))
            if arr[i] >= arr[i-1]:
                sorted_count += 1
        
        if sorted_count == n - 1:
            return 0
            
        rem = n
        prev_idx = list(range(-1, n-1))
        next_idx = list(range(1, n + 1))
        
        while rem > 1 and pq:
            s, left = heapq.heappop(pq)
            right = next_idx[left]
            
            if right >= n or removed[left] or removed[right] or arr[left] + arr[right] != s:
                continue
            
            pre = prev_idx[left]
            nxt = next_idx[right]
            
            if arr[left] <= arr[right]:
                sorted_count -= 1
            if pre != -1 and arr[pre] <= arr[left]:
                sorted_count -= 1
            if nxt != n and arr[right] <= arr[nxt]:
                sorted_count -= 1
                
            arr[left] += arr[right]
            removed[right] = True
            rem -= 1
            
            if pre == -1:
                prev_idx[left] = -1
            else:
                heapq.heappush(pq, (arr[pre] + arr[left], pre))
                if arr[pre] <= arr[left]:
                    sorted_count += 1
            
            if nxt == n:
                next_idx[left] = n
            else:
                prev_idx[nxt] = left
                next_idx[left] = nxt
                heapq.heappush(pq, (arr[left] + arr[nxt], left))
                if arr[left] <= arr[nxt]:
                    sorted_count += 1
                    
            if sorted_count == rem - 1:
                return n - rem
                
        return n