/**
 * @param {number} n
 * @return {number}
 */
const bitwiseComplement = n => {
    if (n === 0) return 1;
    let m = n;
    for (let i = 1; i <= 1 << 4; i <<= 1)
        m |= m >> i;
    return m ^ n;
};