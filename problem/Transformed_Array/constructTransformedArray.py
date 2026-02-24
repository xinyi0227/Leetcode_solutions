class Solution:
    def constructTransformedArray(self, A):
        return [A[(i + v) % len(A)] for i, v in enumerate(A)]