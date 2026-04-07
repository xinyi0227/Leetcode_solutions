/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} k
 * @return {number}
 */
class DSU {
    constructor(n) {
        this.parent = Array.from({ length: n }, (_, i) => i);
        this.rank = new Array(n).fill(0);
        this.components = n;
    }

    find(x) {
        if (this.parent[x] !== x) {
            this.parent[x] = this.find(this.parent[x]);
        }
        return this.parent[x];
    }

    unite(a, b) {
        let rootA = this.find(a);
        let rootB = this.find(b);
        if (rootA === rootB) return false;
        if (this.rank[rootA] < this.rank[rootB]) [rootA, rootB] = [rootB, rootA];
        this.parent[rootB] = rootA;
        if (this.rank[rootA] === this.rank[rootB]) this.rank[rootA]++;
        this.components--;
        return true;
    }
}

var maxStability = function(n, edges, k) {
    const canAchieve = (x) => {
        const dsu = new DSU(n);
        for (const [u, v, s, must] of edges) {
            if (must === 1) {
                if (s < x || !dsu.unite(u, v)) return false;
            }
        }
        for (const [u, v, s, must] of edges) {
            if (must === 0 && s >= x) dsu.unite(u, v);
        }
        let usedUpgrades = 0;
        for (const [u, v, s, must] of edges) {
            if (must === 0 && s < x && 2 * s >= x) {
                if (dsu.unite(u, v)) usedUpgrades++;
            }
        }
        return dsu.components === 1 && usedUpgrades <= k;
    };

    const initialDsu = new DSU(n);
    for (const [u, v, s, must] of edges) {
        if (must === 1 && !initialDsu.unite(u, v)) return -1;
    }

    let low = 1, high = 200000, ans = -1;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (canAchieve(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
};