import heapq

class Solution:
    def maxAverageRatio(self, classes, extraStudents):
        def gain(p, t):
            return (float(p + 1) / (t + 1)) - (float(p) / t)

        heap = []
        for i, (p, t) in enumerate(classes):
            heapq.heappush(heap, (-gain(p, t), i))

        for _ in range(extraStudents):
            _, i = heapq.heappop(heap)
            classes[i][0] += 1
            classes[i][1] += 1
            heapq.heappush(heap, (-gain(classes[i][0], classes[i][1]), i))

        s = 0.0
        for p, t in classes:
            s += float(p) / t
        return s / float(len(classes))
