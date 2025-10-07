class Solution:
    def replaceNonCoprimes(self, nums):
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        st = []
        for num in nums:
            while st:
                g = gcd(st[-1], num)
                if g == 1:
                    break
                num = st[-1] // g * num
                st.pop()
            st.append(num)
        return st
