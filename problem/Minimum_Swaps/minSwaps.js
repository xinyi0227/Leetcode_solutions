/**
 * @param {number[][]} grid
 * @return {number}
 */
const minSwaps = grid => {
    const n = grid.length;
    let Z = grid.map(r => n - 1 - r.lastIndexOf(1));
    let swap = 0;

    for (let i = 0; i < n; i++) {
        const req = n - 1 - i;
        const j = Z.findIndex(c => c >= req);

        if (j === -1) return -1;

        swap += j;
        Z.splice(j, 1)[0];
    }

    return swap;
};