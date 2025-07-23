/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var maximumGain = function(s, x, y) {
    let totalGain = 0;
    let s1 = 'ab', s2 = 'ba';

    if (y > x) {
        [x, y] = [y, x];
        [s1, s2] = ['ba', 'ab'];
    }

    const removePair = (str, firstChar, secondChar, reward) => {
        const stack = [];
        let gain = 0;
        for (let ch of str) {
            if (stack.length && stack.at(-1) === firstChar && ch === secondChar) {
                stack.pop();
                gain += reward;
            } else {
                stack.push(ch);
            }
        }
        return { gain, remainder: stack.join('') };
    };

    const { gain, remainder } = removePair(s, s1[0], s1[1], x);
    totalGain += gain;

    const { gain: gain2 } = removePair(remainder, s2[0], s2[1], y);
    totalGain += gain2;

    return totalGain;
};