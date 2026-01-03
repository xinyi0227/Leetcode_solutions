/**
 * @param {string} corridor
 * @return {number}
 */
var numberOfWays = function(corridor) {
    const mod = 1e9 + 7;
    let s0 = 0, s1 = 0, s2 = 1;
    for (let c of corridor) {
        if (c === 'S') {
            s0 = s1;
            [s1, s2] = [s2, s1];
        } else {
            s2 = (s2 + s0) % mod;
        }
    }
    return s0;
};