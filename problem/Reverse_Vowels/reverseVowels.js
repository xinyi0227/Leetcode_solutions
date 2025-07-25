/**
 * @param {string} s
 * @return {string}
 */
function reverseVowels(s) {
    const chars = s.split('');
    const n = chars.length;
    let low = 0;
    let high = n - 1;
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    
    while (low < high) {
        if (vowels.has(chars[low]) && vowels.has(chars[high])) {
            [chars[low], chars[high]] = [chars[high], chars[low]];
            low++;
            high--;
        } else {
            if (!vowels.has(chars[high])) {
                high--;
            }
            if (!vowels.has(chars[low])) {
                low++;
            }
        }
    }
    
    return chars.join('');
}
