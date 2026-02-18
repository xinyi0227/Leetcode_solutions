/**
 * @param {string} source
 * @param {string} target
 * @param {character[]} original
 * @param {character[]} changed
 * @param {number[]} cost
 * @return {number}
 */
var minimumCost = function(source, target, original, changed, cost) {
    const dist = Array.from({ length: 26 }, () => new Array(26).fill(Infinity));
    
    for (let i = 0; i < 26; ++i) {
        dist[i][i] = 0;
    }
    
    for (let i = 0; i < original.length; ++i) {
        const u = original[i].charCodeAt(0) - 97;
        const v = changed[i].charCodeAt(0) - 97;
        dist[u][v] = Math.min(dist[u][v], cost[i]);
    }
    
    for (let k = 0; k < 26; ++k) {
        for (let i = 0; i < 26; ++i) {
            if (dist[i][k] === Infinity) continue;
            for (let j = 0; j < 26; ++j) {
                if (dist[k][j] !== Infinity) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    let totalCost = 0;
    const n = source.length;
    
    for (let i = 0; i < n; ++i) {
        const u = source.charCodeAt(i) - 97;
        const v = target.charCodeAt(i) - 97;
        if (u === v) continue;
        if (dist[u][v] === Infinity) return -1;
        totalCost += dist[u][v];
    }
    
    return totalCost;
};