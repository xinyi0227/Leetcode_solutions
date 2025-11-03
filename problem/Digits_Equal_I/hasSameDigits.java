class Solution {
    public boolean hasSameDigits(String s) {
        char[] arr = s.toCharArray();
        int iteration = 0;
        
        while (arr.length - iteration != 2) {
            for (int i = 0; i < arr.length - 1 - iteration; i++) {
                arr[i] = (char)(((arr[i] - '0') + (arr[i + 1] - '0')) % 10 + '0');
            }
            iteration++;
        }
        
        return arr[0] == arr[1];
    }
}