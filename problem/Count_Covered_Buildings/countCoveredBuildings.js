/**
 * @param {number} n
 * @param {number[][]} buildings
 * @return {number}
 */
var countCoveredBuildings = function(n, buildings) {
    let M = 0, N = 0;
    for (let i = 0; i < buildings.length; i++) {
        const x = buildings[i][0], y = buildings[i][1];
        if (x > M) M = x;
        if (y > N) N = y;
    }

    const xMin = Array(N + 1).fill(Number.MAX_SAFE_INTEGER);
    const xMax = Array(N + 1).fill(0);
    const yMin = Array(M + 1).fill(Number.MAX_SAFE_INTEGER);
    const yMax = Array(M + 1).fill(0);

    for (let i = 0; i < buildings.length; i++) {
        const x = buildings[i][0], y = buildings[i][1];
        if (x < xMin[y]) xMin[y] = x;
        if (x > xMax[y]) xMax[y] = x;
        if (y < yMin[x]) yMin[x] = y;
        if (y > yMax[x]) yMax[x] = y;
    }

    let cnt = 0;
    for (let i = 0; i < buildings.length; i++) {
        const x = buildings[i][0], y = buildings[i][1];
        const coverX = (xMin[y] < x) & (x < xMax[y]);
        const coverY = (yMin[x] < y) & (y < yMax[x]);
        cnt += (coverX & coverY);
    }
    return cnt;
};
