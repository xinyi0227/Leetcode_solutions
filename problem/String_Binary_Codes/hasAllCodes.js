/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var hasAllCodes = function(s, k) {
    let req = 1 << k;
    let seen = new Uint8Array(req);
    let mask = req - 1;
    let hash = 0;

    for (let i = 0; i < s.length; ++i) {
        hash = ((hash << 1) & mask) | (s.charCodeAt(i) & 1);

        if (i >= k - 1 && !seen[hash]) {
            seen[hash] = 1;
            req--;
            if (req === 0) return true;
        }
    }

    return false;
};