from sortedcontainers import SortedList
from collections import defaultdict

class Solution:
    def findXSum(self, nums, k, x):
        n = len(nums)
        freq = defaultdict(int)
        ans = []

        def key(val):
            return (freq[val], val)

        topX = SortedList(key=key)
        rest = SortedList(key=key)
        sumTop = [0]

        def rebalance():
            while len(topX) < min(x, len(freq)) and len(rest) > 0:
                best = rest.pop(-1)
                topX.add(best)
                sumTop[0] += freq[best] * best
            while len(topX) > x:
                worst = topX.pop(0)
                sumTop[0] -= freq[worst] * worst
                rest.add(worst)
            while len(topX) and len(rest):
                worstTop = topX[0]
                bestRest = rest[-1]
                if (freq[bestRest] > freq[worstTop] or
                    (freq[bestRest] == freq[worstTop] and bestRest > worstTop)):
                    topX.remove(worstTop)
                    rest.remove(bestRest)
                    topX.add(bestRest)
                    rest.add(worstTop)
                    sumTop[0] += freq[bestRest] * bestRest - freq[worstTop] * worstTop
                else:
                    break

        for i, v in enumerate(nums):
            if freq[v] > 0:
                if v in topX:
                    topX.remove(v)
                    sumTop[0] -= freq[v] * v
                else:
                    rest.remove(v)
            freq[v] += 1
            rest.add(v)
            rebalance()

            if i >= k:
                u = nums[i - k]
                if u in topX:
                    topX.remove(u)
                    sumTop[0] -= freq[u] * u
                else:
                    rest.remove(u)
                if freq[u] == 1:
                    del freq[u]
                else:
                    freq[u] -= 1
                    rest.add(u)
                rebalance()

            if i >= k - 1:
                ans.append(sumTop[0])

        return ans