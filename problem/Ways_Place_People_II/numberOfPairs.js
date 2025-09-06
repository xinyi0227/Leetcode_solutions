/**
 * @param {number[][]} points
 * @return {number}
 */
function numberOfPairs(P) {
    P.sort((p, q) => (p[0] == q[0] ? p[1] - q[1] : q[0] - p[0]));
    let ans = 0;
    for (let i = 0; i < P.length - 1; i++) {
        let y = Infinity, yi = P[i][1];
        for (let j = i + 1; j < P.length; j++) {
            let yj = P[j][1];
            if (yj >= yi && y > yj) {
                ans++;
                y = yj;
                if (yi == yj) break;
            }
        }
    }
    return ans;
}
