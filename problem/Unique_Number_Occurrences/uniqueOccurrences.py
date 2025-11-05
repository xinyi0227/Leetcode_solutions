class Solution:
    def uniqueOccurrences(self, arr):
        arr.sort()
        counts = []
        i = 0
        n = len(arr)
        while i < n:
            cnt = 1
            while i + 1 < n and arr[i] == arr[i + 1]:
                cnt += 1
                i += 1
            counts.append(cnt)
            i += 1
        counts.sort()
        for j in range(1, len(counts)):
            if counts[j] == counts[j - 1]:
                return False
        return True
