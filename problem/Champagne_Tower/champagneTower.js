/**
 * @param {number} poured
 * @param {number} query_row
 * @param {number} query_glass
 * @return {number}
 */
var champagneTower = function(poured, query_row, query_glass) {
    let tower = new Array(102).fill(0).map(() => new Array(102).fill(0));
    tower[0][0] = poured;

    for (let r = 0; r <= query_row; r++) {
        for (let c = 0; c <= r; c++) {
            if (tower[r][c] > 1) {
                let excess = (tower[r][c] - 1) / 2.0;
                tower[r][c] = 1;
                tower[r + 1][c] += excess;
                tower[r + 1][c + 1] += excess;
            }
        }
    }
    return tower[query_row][query_glass];
};