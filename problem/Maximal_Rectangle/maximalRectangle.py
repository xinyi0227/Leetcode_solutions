class Solution:
    def area(self, heights):
        n = len(heights)
        st = []
        max_area = 0

        for i in range(n + 1):
            h = 0 if i == n else heights[i]
            while st and h < heights[st[-1]]:
                height = heights[st.pop()]
                width = i if not st else i - st[-1] - 1
                max_area = max(max_area, height * width)
            st.append(i)
        return max_area

    def maximalRectangle(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        
        m, n = len(matrix), len(matrix[0])
        hist = [0] * n
        ans = 0

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    hist[j] += 1
                else:
                    hist[j] = 0
            ans = max(ans, self.area(hist))
        return ans