class Solution:
    def separateSquares(self, squares):
        xs = []
        for s in squares:
            xs.append(float(s[0]))
            xs.append(float(s[0] + s[2]))
        
        xs = sorted(list(set(xs)))
        xi = {x: i for i, x in enumerate(xs)}
        n = len(xs)
        
        cnt = [0] * (4 * n)
        segLen = [0.0] * (4 * n)
        
        def update(idx, l, r, ql, qr, val):
            if qr <= l or r <= ql:
                return
            if ql <= l and r <= qr:
                cnt[idx] += val
            else:
                m = (l + r) >> 1
                update(idx << 1, l, m, ql, qr, val)
                update(idx << 1 | 1, m, r, ql, qr, val)
            
            if cnt[idx] > 0:
                segLen[idx] = xs[r] - xs[l]
            elif r - l == 1:
                segLen[idx] = 0.0
            else:
                segLen[idx] = segLen[idx << 1] + segLen[idx << 1 | 1]

        events = []
        for s in squares:
            x, y, l_ = float(s[0]), float(s[1]), float(s[2])
            events.append((y, x, x + l_, 1))
            events.append((y + l_, x, x + l_, -1))
            
        events.sort(key=lambda x: x[0])
        
        strips = []
        total = 0.0
        prevY = events[0][0]
        
        for y, x1, x2, type_ in events:
            if y > prevY:
                w = segLen[1]
                h = y - prevY
                total += w * h
                strips.append((prevY, h, w))
                prevY = y
            
            l = xi[x1]
            r = xi[x2]
            update(1, 0, n - 1, l, r, type_)
            
        half = total / 2.0
        acc = 0.0
        
        for y, h, w in strips:
            area = h * w
            if acc + area >= half:
                return y + (half - acc) / w
            acc += area
            
        return 0.0