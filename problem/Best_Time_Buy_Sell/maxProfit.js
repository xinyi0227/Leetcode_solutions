/**
 * @param {number[]} prices
 * @param {number[]} strategy
 * @param {number} k
 * @return {number}
 */
var maxProfit = function(prices, strat, k) {
  const n = prices.length;
  const h = Math.floor(k / 2);

  const sp = new Array(n);
  let base = 0n;
  for (let i = 0; i < n; i++) {
    sp[i] = BigInt(strat[i]) * BigInt(prices[i]);
    base += sp[i];
  }

  let ans;
  if (n === k) {
    const winOrig = base;
    let winMod = 0n;
    for (let i = h; i < n; i++) winMod += BigInt(prices[i]);
    const change = winMod - winOrig;
    ans = base + (change > 0n ? change : 0n);
  } else {
    let winOrig = 0n;
    for (let i = 0; i < k; i++) winOrig += sp[i];

    let winMod = 0n;
    for (let i = h; i < k; i++) winMod += BigInt(prices[i]);

    let maxCh = winMod - winOrig;

    for (let i = 1; i <= n - k; i++) {
      winOrig += sp[i + k - 1] - sp[i - 1];
      winMod += BigInt(prices[i + k - 1]) - BigInt(prices[i - 1 + h]);
      const diff = winMod - winOrig;
      if (diff > maxCh) maxCh = diff;
    }

    ans = base + (maxCh > 0n ? maxCh : 0n);
  }

  return Number(ans);
};