/**
 * @param {string} s
 * @return {number}
 */
const numSteps = s => {
    let steps = 0, carry = 0;
    for (let i = s.length - 1; i > 0; i--) {
        const bit = s.charCodeAt(i) & 1;
        steps += 1 + (bit ^ carry);
        carry |= bit;
    }

    return steps + carry;
};