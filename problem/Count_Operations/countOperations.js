/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
function countOperations(num1, num2) {
    let num3 = 0;
    while (num1 > 0 && num2 > 0) {
        if (num1 < num2) { const temp = num1; num1 = num2; num2 = temp; }
        num3 += Math.floor(num1 / num2);
        num1 = num1 % num2;
    }
    return num3;
};