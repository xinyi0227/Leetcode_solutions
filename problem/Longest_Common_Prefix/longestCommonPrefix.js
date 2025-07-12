var longestCommonPrefix = function(strs) {
    if (!strs || strs.length === 0) return "";
    
    let minLen = Math.min(...strs.map(s => s.length));
    
    for (let i = 0; i < minLen; i++) {
        let char = strs[0][i];
        for (let j = 1; j < strs.length; j++) {
            if (strs[j][i] !== char) {
                return strs[0].substring(0, i);
            }
        }
    }
    
    return strs[0].substring(0, minLen);
};

var longestCommonPrefix_horizontal = function(strs) {
    if (!strs || strs.length === 0) return "";
    
    let prefix = strs[0];
    
    for (let i = 1; i < strs.length; i++) {
        let j = 0;
        while (j < prefix.length && j < strs[i].length && 
               prefix[j] === strs[i][j]) {
            j++;
        }
        prefix = prefix.substring(0, j);
        
        if (prefix === "") return "";
    }
    
    return prefix;
};

var longestCommonPrefix_divide_conquer = function(strs) {
    if (!strs || strs.length === 0) return "";
    
    function commonPrefix(left, right) {
        let minLen = Math.min(left.length, right.length);
        for (let i = 0; i < minLen; i++) {
            if (left[i] !== right[i]) {
                return left.substring(0, i);
            }
        }
        return left.substring(0, minLen);
    }
    
    function divideConquer(l, r) {
        if (l === r) return strs[l];
        
        let mid = Math.floor((l + r) / 2);
        let leftPrefix = divideConquer(l, mid);
        let rightPrefix = divideConquer(mid + 1, r);
        
        return commonPrefix(leftPrefix, rightPrefix);
    }
    
    return divideConquer(0, strs.length - 1);
};
