/**
 * @param {number[]} rains
 * @return {number[]}
 */
class UnionFind {
    constructor(size) {
        this.parent = Array.from({ length: size + 1 }, (_, i) => i);
    }

    find(i) {
        if (i === this.parent[i]) {
            return i;
        }
        this.parent[i] = this.find(this.parent[i]);
        return this.parent[i];
    }

    unite(i) {
        this.parent[i] = this.find(i + 1);
    }
}

var avoidFlood = function(rain) {
    const n = rain.length;
    const uf = new UnionFind(n);
    const map = new Map();
    const res = new Array(n).fill(1);

    for (let i = 0; i < n; i++) {
        const lake = rain[i];
        if (lake === 0) continue;

        res[i] = -1;
        uf.unite(i);

        if (map.has(lake)) {
            const prev = map.get(lake);
            const dry = uf.find(prev + 1);

            if (dry >= i) return [];

            res[dry] = lake;
            uf.unite(dry);
            map.set(lake, i);
        } else {
            map.set(lake, i);
        }
    }

    return res;
};