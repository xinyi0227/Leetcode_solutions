/**
 * @param {number[]} nums
 * @return {number}
 */
var longestBalanced = function(nums) {
    class SegTree {
        constructor(n) {
            this.n = n;
            this.sum = new Int32Array(4 * n + 5);
            this.mn = new Int32Array(4 * n + 5);
            this.mx = new Int32Array(4 * n + 5);
            this.lazyVal = new Int32Array(4 * n + 5);
            this.hasLazy = new Int8Array(4 * n + 5);
        }

        pull(v) {
            this.sum[v] = this.sum[v << 1] + this.sum[v << 1 | 1];
            this.mn[v] = Math.min(this.mn[v << 1], this.sum[v << 1] + this.mn[v << 1 | 1]);
            this.mx[v] = Math.max(this.mx[v << 1], this.sum[v << 1] + this.mx[v << 1 | 1]);
        }

        applySet(v, l, r, val) {
            let len = r - l + 1;
            this.sum[v] = val * len;
            if (val === 0) {
                this.mn[v] = 0;
                this.mx[v] = 0;
            } else if (val > 0) {
                this.mn[v] = val;
                this.mx[v] = val * len;
            } else {
                this.mn[v] = val * len;
                this.mx[v] = val;
            }
            this.hasLazy[v] = 1;
            this.lazyVal[v] = val;
        }

        push(v, l, r) {
            if (!this.hasLazy[v] || l === r) return;
            let m = (l + r) >> 1;
            this.applySet(v << 1, l, m, this.lazyVal[v]);
            this.applySet(v << 1 | 1, m + 1, r, this.lazyVal[v]);
            this.hasLazy[v] = 0;
        }

        updatePos(pos, newval) {
            this.update(1, 0, this.n - 1, pos, pos, newval);
        }

        update(v, l, r, ql, qr, val) {
            if (ql <= l && r <= qr) {
                this.applySet(v, l, r, val);
                return;
            }
            this.push(v, l, r);
            let m = (l + r) >> 1;
            if (ql <= m) this.update(v << 1, l, m, ql, qr, val);
            if (qr > m) this.update(v << 1 | 1, m + 1, r, ql, qr, val);
            this.pull(v);
        }

        query(x) {
            if (x === 0) return -1;
            if (x < this.mn[1] || x > this.mx[1]) return this.n;
            let pref = { val: 0 };
            return this.queryRec(1, 0, this.n - 1, x, pref);
        }

        queryRec(v, l, r, x, pref) {
            if (l === r) {
                if (pref.val + this.sum[v] === x) return l;
                return this.n;
            }
            this.push(v, l, r);
            let m = (l + r) >> 1;
            let L = v << 1;
            let R = v << 1 | 1;

            let leftMin = pref.val + this.mn[L];
            let leftMax = pref.val + this.mx[L];

            if (x >= leftMin && x <= leftMax) {
                return this.queryRec(L, l, m, x, pref);
            } else {
                pref.val += this.sum[L];
                return this.queryRec(R, m + 1, r, x, pref);
            }
        }
    }

    let n = nums.length;
    let m = 0;
    for (let x of nums) m = Math.max(m, x);
    
    let lastPos = new Int32Array(m + 1).fill(-1);
    let S = new SegTree(n);
    let sum = 0;
    let ans = 0;

    for (let i = 0; i < n; i++) {
        if (lastPos[nums[i]] !== -1) {
            S.updatePos(lastPos[nums[i]], 0);
        } else {
            if (nums[i] % 2 !== 0) sum++;
            else sum--;
        }

        lastPos[nums[i]] = i;

        if (nums[i] % 2 !== 0) S.updatePos(i, 1);
        else S.updatePos(i, -1);

        let p = S.query(sum);
        ans = Math.max(ans, i - p);
    }

    return ans;
};