/**
 * @param {number[][]} intervals
 * @return {number}
 */
var intersectionSizeTwo = function(intervals) {
    if (!intervals || intervals.length === 0) return 0;
    intervals.sort((a, b) => {
        if (a[1] !== b[1]) return a[1] - b[1];
        return b[0] - a[0];
    });
    let res = 0;
    let a = -Infinity, b = -Infinity;
    for (const [l, r] of intervals) {
        if (l > b) {
            res += 2;
            a = r - 1;
            b = r;
        } else if (l > a) {
            res += 1;
            a = b;
            b = r;
        }
    }
    return res;
};