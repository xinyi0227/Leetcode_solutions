class Solution {
    public int maxVowels(String s, int k) {
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        int max_vowels = 0;
        int curr_vowels = 0;
        int left = 0;
        
        for (int i = 0; i < k; i++) {
            if (vowels.contains(s.charAt(i))) {
                curr_vowels++;
            }
        }
        
        max_vowels = curr_vowels;
        
        for (int i = k; i < s.length(); i++) {
            if (vowels.contains(s.charAt(left))) {
                curr_vowels--;
            }
            left++;
            if (vowels.contains(s.charAt(i))) {
                curr_vowels++;
            }
            max_vowels = Math.max(max_vowels, curr_vowels);
        }
        
        return max_vowels;
    }
}