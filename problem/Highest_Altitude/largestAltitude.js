/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function(gain) {
    let alt = 0;
    let best = 0;

    for (let g of gain) {
        alt += g;
        if (alt > best) {
            best = alt;
        }
    }

    return best;
};