/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
const canBeTypedWords = (text, broken) => {
    const brokenKeys = new Set(broken);
    const words = text.split(" ");
    let count = 0;

    for (const word of words) {
        for (const c of word) {
            if (brokenKeys.has(c)) {
                count++;
                break;
            }
        }
    }

    return words.length - count;
};