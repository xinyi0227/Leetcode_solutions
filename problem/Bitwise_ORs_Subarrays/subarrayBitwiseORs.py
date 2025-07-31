class Solution:
    def subarrayBitwiseORs(self, arr):
        res = set()
        cur = set()

        for num in arr:
            next_set = {num}
            for x in cur:
                next_set.add(x | num)
            cur = next_set
            res.update(cur)

        return len(res)