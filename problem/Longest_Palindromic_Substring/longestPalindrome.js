/**
 * Expand around centers - O(n^2) time, O(1) space
 */
var longestPalindrome = function(s) {
    if (!s || s.length === 0) return "";
    
    let start = 0, maxLen = 1;
    for (let i = 0; i < s.length; i++) {
        const len1 = expandAroundCenter(s, i, i); 
        const len2 = expandAroundCenter(s, i, i + 1); 
        
        const currentMax = Math.max(len1, len2);
        if (currentMax > maxLen) {
            maxLen = currentMax;
            start = i - Math.floor((currentMax - 1) / 2);
        }
    }
    
    return s.substring(start, start + maxLen);
};

function expandAroundCenter(s, left, right) {
    while (left >= 0 && right < s.length && s[left] === s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

/**
 * Dynamic programming approach - O(n^2) time, O(n^2) space
 */
var longestPalindrome_dp = function(s) {
    const n = s.length;
    if (n === 0) return "";
    
    const dp = Array(n).fill().map(() => Array(n).fill(false));
    let start = 0, maxLen = 1;

    for (let i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (let i = 0; i < n - 1; i++) {
        if (s[i] === s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    for (let len = 3; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            if (s[i] === s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }
    
    return s.substring(start, start + maxLen);
};

/**
 * Optimized expand around centers
 */
var longestPalindrome_optimized = function(s) {
    if (!s || s.length === 0) return "";
    
    let start = 0, maxLen = 1;
    for (let i = 0; i < s.length; i++) {
        if (s.length - i <= maxLen / 2) break;
        
        let left = i, right = i;
        while (right < s.length - 1 && s[right] === s[right + 1]) {
            right++;
        }
        
        i = right;

        while (left > 0 && right < s.length - 1 && s[left - 1] === s[right + 1]) {
            left--;
            right++;
        }
        
        const currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
            start = left;
        }
    }
    
    return s.substring(start, start + maxLen);
};

/**
 * Manacher's algorithm - O(n) time, O(n) space
 */
var longestPalindrome_manacher = function(s) {
    if (!s || s.length === 0) return "";

    let processed = "^#" + s.split('').join('#') + "#$";
    const n = processed.length;
    const lengths = new Array(n).fill(0);

    let center = 0, right = 0;
    for (let i = 1; i < n - 1; i++) {
        const mirror = 2 * center - i;
        
        if (i < right) {
            lengths[i] = Math.min(right - i, lengths[mirror]);
        }
        
        while (processed[i + lengths[i] + 1] === processed[i - lengths[i] - 1]) {
            lengths[i]++;
        }

        if (i + lengths[i] > right) {
            center = i;
            right = i + lengths[i];
        }
    }

    let maxLen = 0, centerIndex = 0;
    for (let i = 1; i < n - 1; i++) {
        if (lengths[i] > maxLen) {
            maxLen = lengths[i];
            centerIndex = i;
        }
    }
    
    const start = Math.floor((centerIndex - maxLen) / 2);
    return s.substring(start, start + maxLen);
};
