/**
 * @param {string} s
 * @return {number}
 */
const minimumDeletions = s => {
    let res = 0;
    let b = 0;

    for (const c of s) {
        if (c === 'b')
            b++;
        else if (b) {
            res++;
            b--;
        }
    }

    return res;
};