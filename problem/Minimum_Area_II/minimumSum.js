/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumSum = function(grid) {
    const n = grid.length, m = grid[0].length;
    const A = new Array(n).fill(0);
    const T = new Array(m).fill(0);
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === 0) continue;
            A[i] |= (1 << j);
            T[j] |= (1 << i);
        }
    }
    
    function minRect(i0, iN, j0, jN) {
        let iMin = 30, iMax = -1, jMin = 30, jMax = -1;
        for (let i = i0; i <= iN; i++) {
            const row = A[i];
            let mRow = (row >> j0) << j0;
            mRow &= ((1 << (jN + 1)) - 1);
            if (mRow) {
                iMin = i;
                break;
            }
        }
        if (iMin === 30) return 1e8;
        for (let i = iN; i >= iMin; i--) {
            const row = A[i];
            let mRow = (row >> j0) << j0;
            mRow &= ((1 << (jN + 1)) - 1);
            if (mRow) {
                iMax = i;
                break;
            }
        }
        for (let j = j0; j <= jN; j++) {
            const col = T[j];
            let mCol = (col >> i0) << i0;
            mCol &= ((1 << (iN + 1)) - 1);
            if (mCol) {
                jMin = j;
                break;
            }
        }
        for (let j = jN; j >= jMin; j--) {
            const col = T[j];
            let mCol = (col >> i0) << i0;
            mCol &= ((1 << (iN + 1)) - 1);
            if (mCol) {
                jMax = j;
                break;
            }
        }
        return (iMax - iMin + 1) * (jMax - jMin + 1);
    }
    
    let ans = 2**32;
    
    for (let c1 = 0; c1 < m - 2; c1++) {
        for (let c2 = c1 + 1; c2 < m - 1; c2++) {
            const a = minRect(0, n - 1, 0, c1);
            const b = minRect(0, n - 1, c1 + 1, c2);
            const c = minRect(0, n - 1, c2 + 1, m - 1);
            ans = Math.min(ans, a + b + c);
        }
    }
    
    for (let r1 = 0; r1 < n - 2; r1++) {
        for (let r2 = r1 + 1; r2 < n - 1; r2++) {
            const a = minRect(0, r1, 0, m - 1);
            const b = minRect(r1 + 1, r2, 0, m - 1);
            const c = minRect(r2 + 1, n - 1, 0, m - 1);
            ans = Math.min(ans, a + b + c);
        }
    }
    
    for (let r = 0; r < n - 1; r++) {
        for (let c = 0; c < m - 1; c++) {
            const top = minRect(0, r, 0, m - 1);
            const bl = minRect(r + 1, n - 1, 0, c);
            const br = minRect(r + 1, n - 1, c + 1, m - 1);
            ans = Math.min(ans, top + bl + br);
            
            const bottom = minRect(r + 1, n - 1, 0, m - 1);
            const tl = minRect(0, r, 0, c);
            const tr = minRect(0, r, c + 1, m - 1);
            ans = Math.min(ans, bottom + tl + tr);
            
            const left = minRect(0, n - 1, 0, c);
            const tr2 = minRect(0, r, c + 1, m - 1);
            const br2 = minRect(r + 1, n - 1, c + 1, m - 1);
            ans = Math.min(ans, left + tr2 + br2);
            
            const right = minRect(0, n - 1, c + 1, m - 1);
            const tl2 = minRect(0, r, 0, c);
            const bl2 = minRect(r + 1, n - 1, 0, c);
            ans = Math.min(ans, right + tl2 + bl2);
        }
    }
    
    return ans;
};
