/**
 * @param {number[][]} grid
 * @return {number}
 */
function swimInWater(grid) {
  const n = grid.length;
  const dirs = [[0, -1], [0, 1], [-1, 0], [1, 0]];
  function dfs(x, y, t, vis) {
    if (x === n - 1 && y === n - 1) return true;
    vis[x][y] = true;
    for (const [dx, dy] of dirs) {
      const nx = x + dx, ny = y + dy;
      if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] <= t) {
        if (dfs(nx, ny, t, vis)) return true;
      }
    }
    return false;
  }
  let low = 0, high = n * n - 1, ans = high;
  while (low <= high) {
    const mid = (low + high) >> 1;
    if (grid[0][0] <= mid) {
      const vis = Array.from({ length: n }, () => Array(n).fill(false));
      if (dfs(0, 0, mid, vis)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else {
      low = mid + 1;
    }
  }
  return ans;
}
