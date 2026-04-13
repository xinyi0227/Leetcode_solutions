/**
 * @param {character[][]} grid
 * @return {number}
 */
var numberOfSubmatrices = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const sumX = new Array(cols).fill(0);
    const sumY = new Array(cols).fill(0);
    let res = 0;

    for (let i = 0; i < rows; i++) {
        let rx = 0, ry = 0;
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === 'X') rx++;
            else if (grid[i][j] === 'Y') ry++;
            sumX[j] += rx;
            sumY[j] += ry;
            if (sumX[j] > 0 && sumX[j] === sumY[j]) res++;
        }
    }

    return res;
};