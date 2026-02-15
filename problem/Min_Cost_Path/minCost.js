/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var minCost = function(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        adj[u].push([w, v]);
        adj[v].push([2 * w, u]);
    }

    const minHeap = [];
    
    function push(d, u) {
        minHeap.push([d, u]);
        let i = minHeap.length - 1;
        while (i > 0) {
            const p = (i - 1) >>> 1;
            if (minHeap[p][0] <= minHeap[i][0]) break;
            [minHeap[p], minHeap[i]] = [minHeap[i], minHeap[p]];
            i = p;
        }
    }

    function pop() {
        if (minHeap.length === 0) return null;
        const res = minHeap[0];
        const last = minHeap.pop();
        if (minHeap.length > 0) {
            minHeap[0] = last;
            let i = 0;
            const len = minHeap.length;
            while (true) {
                let left = (i << 1) + 1;
                let right = left + 1;
                let swap = null;

                if (left < len) {
                    if (minHeap[left][0] < minHeap[i][0]) swap = left;
                }
                if (right < len) {
                    if ((swap === null && minHeap[right][0] < minHeap[i][0]) ||
                        (swap !== null && minHeap[right][0] < minHeap[swap][0])) {
                        swap = right;
                    }
                }
                if (swap === null) break;
                [minHeap[i], minHeap[swap]] = [minHeap[swap], minHeap[i]];
                i = swap;
            }
        }
        return res;
    }

    const dist = new Uint32Array(n).fill(-1);
    dist[0] = 0;
    push(0, 0);

    while (minHeap.length > 0) {
        const [d, u] = pop();

        if (d > dist[u]) continue;
        if (u === n - 1) return d;

        for (const [w, v] of adj[u]) {
            const d2 = d + w;
            if (d2 < dist[v]) {
                dist[v] = d2;
                push(d2, v);
            }
        }
    }

    return -1;
};