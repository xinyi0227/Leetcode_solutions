class Solution {
    public String multiply(String num1, String num2) {
        int n1 = num1.length(), n2 = num2.length();
        int[] num = new int[n1 + n2];

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                int sum = num[i + j + 1] + mul;
                num[i + j + 1] = sum % 10;
                num[i + j] += sum / 10;
            }
        }

        StringBuilder res = new StringBuilder();
        int i = 0;
        while (i < num.length && num[i] == 0)
            i++;

        for (; i < num.length; i++) {
            res.append(num[i]);
        }

        return res.length() == 0 ? "0" : res.toString();
    }
}
