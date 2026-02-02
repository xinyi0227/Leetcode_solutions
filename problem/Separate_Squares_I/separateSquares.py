class Solution:
    def separateSquares(self, squares):
        l, r = float('inf'), float('-inf')
        for _, y, side in squares:
            l = min(l, float(y))
            r = max(r, float(y + side))
        
        def validate(mid):
            below, above = 0.0, 0.0
            for _, y, side in squares:
                y_top = y + side
                if y_top <= mid:
                    below += side * side
                elif y >= mid:
                    above += side * side
                else:
                    below += side * (mid - y)
                    above += side * (y_top - mid)
            return below >= above

        for _ in range(100):
            mid = (l + r) / 2
            if validate(mid):
                r = mid
            else:
                l = mid
        return l