class Solution:
    def judgePoint24(self, cards):
        def dfs(nums):
            n = len(nums)
            if n == 1:
                return abs(nums[0] - 24) < 1e-6
            
            for i in range(n):
                for j in range(n):
                    if i != j:
                        remaining = [nums[k] for k in range(n) if k != i and k != j]
                        
                        a, b = nums[i], nums[j]

                        operations = [
                            a + b,
                            a - b,
                            a * b
                        ]
                        
                        if abs(b) > 1e-6:
                            operations.append(a / b)
                        
                        for result in operations:
                            if dfs(remaining + [result]):
                                return True
            
            return False
        
        return dfs([float(x) for x in cards])
