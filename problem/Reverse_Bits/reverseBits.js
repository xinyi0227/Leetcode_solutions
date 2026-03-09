/**
 * @param {number} n 
 * @return {number}
 */
var reverseBits = function(n) {
    const rev = (v, len) => {
        if (len === 1) return v & 1;

        let half = len >> 1;
        let mask = (1 << half) - 1;
        let lo = v & mask;
        let hi = v >>> half;

        return ((rev(lo, half) << half) | rev(hi, half)) >>> 0;
    };

    return rev(n, 32);
};