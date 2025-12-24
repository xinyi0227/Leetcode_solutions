/**
 * @param {number} n
 * @return {number}
 */
var gcd = function (a, b) {
  while (b !== 0) {
    a %= b;
    const t = a;
    a = b;
    b = t;
  }
  return a;
};

var countTriples = function (n) {
  let cnt = 0;
  for (let m = 2; m * m < n; m++) {
    for (let k = 1; k < m; k++) {
      if (gcd(m, k) === 1 && ((m - k) & 1)) {
        const c = m * m + k * k;
        if (c > n) break;
        cnt += 2 * Math.floor(n / c);
      }
    }
  }
  return cnt;
};
