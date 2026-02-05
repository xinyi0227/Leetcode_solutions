/**
 * @param {number[][]} bottomLeft
 * @param {number[][]} topRight
 * @return {number}
 */
var largestSquareArea = function(bottomLeft, topRight) {
    const n = bottomLeft.length;
    const rects = [];
    
    for (let i = 0; i < n; i++) {
        rects.push([bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]]);
    }
    
    // Sort logic handles standard numbers correctly
    rects.sort((a, b) => {
        if (a[0] !== b[0]) return a[0] - b[0];
        if (a[1] !== b[1]) return a[1] - b[1];
        if (a[2] !== b[2]) return a[2] - b[2];
        return a[3] - b[3];
    });
    
    let maxSide = 0;
    
    for (let r = 1; r < n; r++) {
        const [a, b, c, d] = rects[r];
        for (let l = 0; l < r; l++) {
            const [, bj, cj, dj] = rects[l];
            
            // Use standard Math functions and numbers
            const width = Math.min(cj, c) - a;
            const height = Math.min(dj, d) - Math.max(bj, b);
            
            const s = Math.min(width, height);
            
            if (s > maxSide) {
                maxSide = s;
            }
        }
    }
    
    return maxSide * maxSide;
};