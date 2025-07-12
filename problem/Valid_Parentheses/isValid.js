var isValid = function(s) {
    const stack = [];
    const mapping = {
        ')': '(',
        '}': '{',
        ']': '['
    };
    
    for (let char of s) {
        if (char in mapping) {  
            if (stack.length === 0 || stack.pop() !== mapping[char]) {
                return false;
            }
        } else {  
            stack.push(char);
        }
    }
    
    return stack.length === 0;
};

var isValid_optimized = function(s) {
    const stack = [];
    
    for (let char of s) {
        if (char === '(' || char === '[' || char === '{') {
            stack.push(char);
        } else {
            if (stack.length === 0) return false;
            
            const top = stack.pop();
            
            if ((char === ')' && top !== '(') ||
                (char === ']' && top !== '[') ||
                (char === '}' && top !== '{')) {
                return false;
            }
        }
    }
    
    return stack.length === 0;
};

var isValid_replacement = function(s) {
    while (s.includes('()') || s.includes('[]') || s.includes('{}')) {
        s = s.replace('()', '').replace('[]', '').replace('{}', '');
    }
    return s === '';
};
