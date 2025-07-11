var romanToInt = function(s) {
    const romanValues = {
        'I': 1, 'V': 5, 'X': 10, 'L': 50,
        'C': 100, 'D': 500, 'M': 1000
    };
    
    let total = 0;
    
    for (let i = 0; i < s.length; i++) {
        if (i + 1 < s.length && romanValues[s[i]] < romanValues[s[i + 1]]) {
            total += romanValues[s[i + 1]] - romanValues[s[i]];
            i++; 
        } else {
            total += romanValues[s[i]];
        }
    }
    
    return total;
};

var romanToInt_pattern = function(s) {
    const patterns = {
        'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900
    };
    
    const values = {
        'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000
    };
    
    let total = 0;
    let i = 0;
    
    while (i < s.length) {
        if (i + 1 < s.length && patterns[s.substr(i, 2)]) {
            total += patterns[s.substr(i, 2)];
            i += 2;
        } else {
            total += values[s[i]];
            i++;
        }
    }
    
    return total;
};
