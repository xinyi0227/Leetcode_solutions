class Solution {
    public String reverseVowels(String s) {
        char[] chars = s.toCharArray();
        int n = chars.length;
        int low = 0;
        int high = n - 1;
        String vowels = "aeiouAEIOU";

        while (low < high) {
            if (vowels.indexOf(chars[low]) != -1 && vowels.indexOf(chars[high]) != -1) {
                char temp = chars[low];
                chars[low] = chars[high];
                chars[high] = temp;
                low++;
                high--;
            } else {
                if (vowels.indexOf(chars[high]) == -1) {
                    high--;
                }
                if (vowels.indexOf(chars[low]) == -1) {
                    low++;
                }
            }
        }

        return new String(chars);
    }
}
