class Solution:
    def pyramidTransition(self, bottom, allowed):
        pattern = [0] * 36
        bad = [set() for _ in range(8)]

        for s in allowed:
            idx = (ord(s[0]) - 65) * 6 + (ord(s[1]) - 65)
            pattern[idx] |= 1 << (ord(s[2]) - 65)

        def encode(s):
            ans = 0
            for c in s:
                ans = ans * 7 + (ord(c) - 65)
            return ans

        def check(cur):
            for i in range(len(cur) - 1):
                if cur[i] == 'G': return False
                key = (ord(cur[i]) - 65) * 6 + (ord(cur[i+1]) - 65)
                if not pattern[key]: return False
            return True

        def dfs(cur, next_chars, i, sz):
            if i == sz - 1:
                next_str = "".join(next_chars)
                if sz == 2:
                    return True
                if not check(next_str):
                    return False
                
                idx = encode(next_str)
                if idx in bad[sz - 1]:
                    return False

                up = ['G'] * (sz - 2)
                if not dfs(next_str, up, 0, sz - 1):
                    bad[sz - 1].add(idx)
                    return False
                return True

            key = (ord(cur[i]) - 65) * 6 + (ord(cur[i+1]) - 65)
            mask = pattern[key]

            while mask:
                bit = mask & -mask
                mask -= bit
                c = bit.bit_length() - 1
                next_chars[i] = chr(65 + c)
                if dfs(cur, next_chars, i + 1, sz):
                    return True
            return False

        return dfs(bottom, ['G'] * (len(bottom) - 1), 0, len(bottom))