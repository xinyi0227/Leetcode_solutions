/**
 * @param {number} m
 * @param {number} n
 * @param {number[]} hFences
 * @param {number[]} vFences
 * @return {number}
 */
var maximizeSquareArea = function(m, n, hFences, vFences) {
    hFences.push(1, m);
    vFences.push(1, n);

    hFences.sort((a, b) => a - b);
    vFences.sort((a, b) => a - b);

    const hGaps = new Set();
    for (let i = 0; i < hFences.length; i++) {
        for (let j = i + 1; j < hFences.length; j++) {
            hGaps.add(hFences[j] - hFences[i]);
        }
    }

    let maxSide = -1;
    for (let i = 0; i < vFences.length; i++) {
        for (let j = i + 1; j < vFences.length; j++) {
            const currentGap = vFences[j] - vFences[i];
            if (hGaps.has(currentGap)) {
                if (currentGap > maxSide) {
                    maxSide = currentGap;
                }
            }
        }
    }

    if (maxSide === -1) return -1;

    return Number((BigInt(maxSide) * BigInt(maxSide)) % 1000000007n);
};