/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
    let ans = 0;
    
    for (let i = 0; i < chars.length;) {
        const letter = chars[i];
        let count = 0;
        
        while (i < chars.length && chars[i] === letter) {
            count++;
            i++;
        }
        
        chars[ans++] = letter;
        
        if (count > 1) {
            for (const c of count.toString()) {
                chars[ans++] = c;
            }
        }
    }
    
    return ans;
};
