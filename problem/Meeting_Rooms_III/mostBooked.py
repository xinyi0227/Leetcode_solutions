class Solution:
    def mostBooked(self, n, meetings):
        ans = [0] * n
        times = [0] * n
        meetings.sort()

        for start, end in meetings:
            flag = False
            minind = -1
            val = 10**30

            for j in range(n):
                if times[j] < val:
                    val = times[j]
                    minind = j
                if times[j] <= start:
                    flag = True
                    ans[j] += 1
                    times[j] = end
                    break

            if not flag:
                ans[minind] += 1
                times[minind] += end - start

        maxi = -1
        idx = -1
        for i in range(n):
            if ans[i] > maxi:
                maxi = ans[i]
                idx = i
        return idx