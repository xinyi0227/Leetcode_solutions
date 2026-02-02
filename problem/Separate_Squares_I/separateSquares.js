/**
 * @param {number[][]} squares
 * @return {number}
 */
var separateSquares = function(squares) {
    let l = Infinity, r = -Infinity;
    for (const [x, y, side] of squares) {
        l = Math.min(l, y);
        r = Math.max(r, y + side);
    }

    for (let i = 0; i < 100; i++) {
        let mid = (l + r) / 2;
        if (validate(squares, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
};

function validate(squares, mid) {
    let below = 0, above = 0;
    for (const [x, y, side] of squares) {
        let y1 = y + side;
        below += Math.max(0, (Math.min(y1, mid) - y) * side);
        above += Math.max(0, (y1 - Math.max(mid, y)) * side);
    }
    return below >= above;
}