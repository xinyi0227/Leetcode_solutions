/**
 * @param {number[]} fruits
 * @param {number[]} baskets
 * @return {number}
 */
var numOfUnplacedFruits = function(fruits, baskets) {
    const n = fruits.length;
    const seg = new Array(4 * n + 1).fill(0);
    
    function update(p) {
        seg[p] = Math.max(seg[p << 1], seg[p << 1 | 1]);
    }
    
    function build(p, l, r) {
        if (l === r) {
            seg[p] = baskets[l];
            return;
        }
        const mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        update(p);
    }
    
    function assign(x, v, p, l, r) {
        if (x < l || x > r) {
            return;
        }
        if (l === r) {
            seg[p] = v;
            return;
        }
        const mid = (l + r) >> 1;
        assign(x, v, p << 1, l, mid);
        assign(x, v, p << 1 | 1, mid + 1, r);
        update(p);
    }
    
    function firstLarger(v, p, l, r) {
        if (seg[p] < v) {
            return r + 1;
        }
        if (l === r) {
            return r;
        }
        const mid = (l + r) >> 1;
        const lf = firstLarger(v, p << 1, l, mid);
        if (lf <= mid) {
            return lf;
        }
        return firstLarger(v, p << 1 | 1, mid + 1, r);
    }
    
    build(1, 0, n - 1);
    
    let res = 0;
    for (const x of fruits) {
        const pos = firstLarger(x, 1, 0, n - 1);
        if (pos === n) {
            res++;
        } else {
            assign(pos, 0, 1, 0, n - 1);
        }
    }
    
    return res;
};
