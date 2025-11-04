/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function(s, k) {
    let vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let max_vowels = 0;
    let curr_vowels = 0;
    let left = 0;
    
    for (let i = 0; i < k; i++) {
        if (vowels.has(s[i])) {
            curr_vowels++;
        }
    }
    
    max_vowels = curr_vowels;
    
    for (let i = k; i < s.length; i++) {
        if (vowels.has(s[left])) {
            curr_vowels--;
        }
        left++;
        if (vowels.has(s[i])) {
            curr_vowels++;
        }
        max_vowels = Math.max(max_vowels, curr_vowels);
    }
    
    return max_vowels;
};