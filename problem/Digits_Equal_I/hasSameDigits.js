/**
 * @param {string} s
 * @return {boolean}
 */
var hasSameDigits = function(s) {
    let arr = s.split('');
    let iteration = 0;
    
    while (arr.length - iteration !== 2) {
        for (let i = 0; i < arr.length - 1 - iteration; i++) {
            arr[i] = String((parseInt(arr[i]) + parseInt(arr[i + 1])) % 10);
        }
        iteration++;
    }
    
    return arr[0] === arr[1];
};