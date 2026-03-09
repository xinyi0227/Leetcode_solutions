/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
const addBinary = (a, b) => {
    const max = Math.max(a.length, b.length);
    let carry = 0;
    const res = [];

    const sum = (A, B, C) => (A ^ B) ^ C;
    const carr = (A, B, C) => (A & B) | ((A ^ B) & C);

    for (let i = 0; i < max; i++) {
        const A = +(a.at(-1 - i) ?? 0);
        const B = +(b.at(-1 - i) ?? 0);

        res.push(sum(A, B, carry));
        carry = carr(A, B, carry);
    }

    if (carry) res.push(carry);

    return res.reverse().join("");
};