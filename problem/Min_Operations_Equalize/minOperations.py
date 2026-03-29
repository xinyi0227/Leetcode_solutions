class Solution:
    def minOperations(self, s: str, k: int) -> int:
        zero = 0
        length = len(s)

        for char in s:
            zero += ~ord(char) & 1

        if not zero:
            return 0

        if length == k:
            return ((zero == length) << 1) - 1

        base = length - k

        odd = max(
            (zero + k - 1) // k,
            (length - zero + base - 1) // base
        )
        odd += ~odd & 1

        even = max(
            (zero + k - 1) // k,
            (zero + base - 1) // base
        )
        even += even & 1

        res = float('inf')

        if (k & 1) == (zero & 1):
            res = min(res, odd)

        if ~zero & 1:
            res = min(res, even)

        return int(res) if res != float('inf') else -1