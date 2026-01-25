/**
 * @param {number} row
 * @param {number} col
 * @param {number[][]} cells
 * @return {number}
 */
var latestDayToCross = function (row, col, cells) {
  const isPossible = (m, n, t) => {
    const grid = Array.from({ length: m + 1 }, () => new Uint8Array(n + 1));
    for (let i = 0; i < t; i++) {
      const [r, c] = cells[i];
      grid[r][c] = 1;
    }

    const qr = new Int32Array(m * n + 5);
    const qc = new Int32Array(m * n + 5);
    let head = 0, tail = 0;

    for (let c = 1; c <= n; c++) {
      if (grid[1][c] === 0) {
        qr[tail] = 1;
        qc[tail] = c;
        tail++;
        grid[1][c] = 1;
      }
    }

    const dr = [1, -1, 0, 0];
    const dc = [0, 0, 1, -1];

    while (head < tail) {
      const r = qr[head], c = qc[head];
      head++;
      for (let k = 0; k < 4; k++) {
        const nr = r + dr[k], nc = c + dc[k];
        if (nr > 0 && nc > 0 && nr <= m && nc <= n && grid[nr][nc] === 0) {
          grid[nr][nc] = 1;
          if (nr === m) return true;
          qr[tail] = nr;
          qc[tail] = nc;
          tail++;
        }
      }
    }
    return false;
  };

  let left = 0, right = row * col, ans = 0;
  while (left < right - 1) {
    const mid = left + ((right - left) >> 1);
    if (isPossible(row, col, mid)) {
      left = mid;
      ans = mid;
    } else {
      right = mid;
    }
  }
  return ans;
};