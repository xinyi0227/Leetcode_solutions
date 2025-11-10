/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} guards
 * @param {number[][]} walls
 * @return {number}
 */
var countUnguarded = function(m, n, guards, walls) {
    let vis = Array.from({length: m}, () => Array(n).fill(0));
    let mp = Array.from({length: m}, () => Array(n).fill(0));
    
    function dfs(r, c, dir) {
        if (r < 0 || c < 0 || r >= m || c >= n) return;
        if (mp[r][c]) return;
        vis[r][c] = 1;
        
        if (dir === 'r') {
            dfs(r, c + 1, 'r');
        }
        if (dir === 'l') {
            dfs(r, c - 1, 'l');
        }
        if (dir === 'u') {
            dfs(r - 1, c, 'u');
        }
        if (dir === 'd') {
            dfs(r + 1, c, 'd');
        }
    }
    
    for (let [r, c] of guards) {
        mp[r][c] = 1;
        vis[r][c] = 1;
    }
    
    for (let [r, c] of walls) {
        mp[r][c] = 1;
        vis[r][c] = 1;
    }
    
    for (let [r, c] of guards) {
        dfs(r, c + 1, 'r');
        dfs(r, c - 1, 'l');
        dfs(r + 1, c, 'd');
        dfs(r - 1, c, 'u');
    }
    
    let cnt = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (vis[i][j] === 0) cnt++;
        }
    }
    
    return cnt;
};