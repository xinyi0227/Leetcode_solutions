class Solution:
    def countOperations(self, a, b):
        return 0 if not a or not b else a // b + self.countOperations(b, a % b)