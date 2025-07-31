class Solution:
    def multiply(self, num1, num2):
        n1, n2 = len(num1), len(num2)
        num = [0] * (n1 + n2)

        for i in range(n1 - 1, -1, -1):
            for j in range(n2 - 1, -1, -1):
                mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                sum_ = num[i + j + 1] + mul
                num[i + j + 1] = sum_ % 10
                num[i + j] += sum_ // 10

        i = 0
        while i < len(num) - 1 and num[i] == 0:
            i += 1

        return ''.join(str(d) for d in num[i:])
