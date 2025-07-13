/**
 * Brute force approach - O(n*m) time, O(1) space
 */
var strStr = function(haystack, needle) {
    if (needle === '') 
        return 0;
    
    const haystackLen = haystack.length;
    const needleLen = needle.length;
    
    for (let i = 0; i <= haystackLen - needleLen; i++) {
        if (haystack.substring(i, i + needleLen) === needle) {
            return i;
        }
    }
    
    return -1;
};

/**
 * Using built-in indexOf method
 */
var strStr_builtin = function(haystack, needle) {
    if (needle === '') 
        return 0;
    
    return haystack.indexOf(needle);
};

/**
 * Manual character-by-character checking
 */
var strStr_manual = function(haystack, needle) {
    if (needle === '') 
        return 0;
    
    const haystackLen = haystack.length;
    const needleLen = needle.length;
    
    for (let i = 0; i <= haystackLen - needleLen; i++) {
        let match = true;
        for (let j = 0; j < needleLen; j++) {
            if (haystack[i + j] !== needle[j]) {
                match = false;
                break;
            }
        }
        if (match) 
            return i;
    }
    
    return -1;
};

/**
 * KMP algorithm implementation
 */
var strStr_kmp = function(haystack, needle) {
    if (needle === '') 
        return 0;
    
    function buildLPS(pattern) {
        const lps = new Array(pattern.length).fill(0);
        let len = 0;
        let i = 1;
        
        while (i < pattern.length) {
            if (pattern[i] === pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len !== 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    const lps = buildLPS(needle);
    let i = 0;
    let j = 0; 
    
    while (i < haystack.length) {
        if (haystack[i] === needle[j]) {
            i++;
            j++;
        }
        
        if (j === needle.length) {
            return i - j;
        } else if (i < haystack.length && haystack[i] !== needle[j]) {
            if (j !== 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return -1;
};
