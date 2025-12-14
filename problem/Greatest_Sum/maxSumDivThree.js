/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSumDivThree = function(nums) {
    let sum = 0;
    
    let min1 = Infinity, min2 = Infinity;
    let min11 = Infinity, min22 = Infinity;
    
    for (let x of nums) {
        sum += x;
        let r = x % 3;
        
        if (r == 1) {
            if (x < min1) { min11 = min1; min1 = x; }
            else if (x < min11) min11 = x;
        } else if (r == 2) {
            if (x < min2) { min22 = min2; min2 = x; }
            else if (x < min22) min22 = x;
        }
    }
    
    let rem = sum % 3;
    
    if (rem == 0) return sum;
    
    if (rem == 1) {
        let r1 = min1;
        let r2 = (min2 == Infinity || min22 == Infinity) ? Infinity : min2 + min22;
        let remove = Math.min(r1, r2);
        return remove == Infinity ? 0 : sum - remove;
    } else {
        let r1 = min2;
        let r2 = (min1 == Infinity || min11 == Infinity) ? Infinity : min1 + min11;
        let remove = Math.min(r1, r2);
        return remove == Infinity ? 0 : sum - remove;
    }
};