/**
 * @param {number[][]} heights
 * @return {number[][]}
 */
var pacificAtlantic = function(heights) {
    const m = heights.length, n = heights[0].length;
    const directions = [[1,0], [-1,0], [0,1], [0,-1]];

    function dfs(startCells) {
        const visited = Array.from({ length: m }, () => Array(n).fill(false));
        const stack = [...startCells];
        while (stack.length) {
            const [i, j] = stack.pop();
            if (visited[i][j]) continue;
            visited[i][j] = true;
            for (let [dx, dy] of directions) {
                const x = i + dx, y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n &&
                    !visited[x][y] && heights[x][y] >= heights[i][j]) {
                    stack.push([x, y]);
                }
            }
        }
        return visited;
    }

    const pacificStarts = [];
    for (let j = 0; j < n; j++) pacificStarts.push([0, j]);
    for (let i = 0; i < m; i++) pacificStarts.push([i, 0]);
    const atlanticStarts = [];
    for (let j = 0; j < n; j++) atlanticStarts.push([m-1, j]);
    for (let i = 0; i < m; i++) atlanticStarts.push([i, n-1]);

    const pacific = dfs(pacificStarts);
    const atlantic = dfs(atlanticStarts);

    const result = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push([i, j]);
            }
        }
    }
    return result;
};