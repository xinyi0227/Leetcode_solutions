/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
function divide(dividend, divisor) {
    const INT_MIN = -Math.pow(2, 31);
    const INT_MAX = Math.pow(2, 31) - 1;
    
    if (dividend === INT_MIN && divisor === -1) {
        return INT_MAX;
    }
    
    return Math.trunc(dividend / divisor);
}
