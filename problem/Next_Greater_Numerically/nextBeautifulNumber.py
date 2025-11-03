class Solution:
    def nextBeautifulNumber(self, n):
        def is_beautiful(num):
            s = str(num)
            count = [0] * 10
            for c in s:
                count[int(c)] += 1
            for d in range(10):
                if count[d] != 0 and count[d] != d:
                    return False
            return True
        
        num = n + 1
        while num <= 1224444:
            if is_beautiful(num):
                return num
            num += 1
        return -1