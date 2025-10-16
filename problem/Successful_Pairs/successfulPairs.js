/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */
var successfulPairs = function(spells, potions, success) {
  potions.sort((a, b) => a - b);
  const m = potions.length;
  const res = new Array(spells.length);
  const lowerBound = (x) => {
    let l = 0, r = m - 1, ans = m;
    while (l <= r) {
      const mid = (l + r) >> 1;
      if (potions[mid] >= x) { ans = mid; r = mid - 1; }
      else l = mid + 1;
    }
    return ans;
  };
  for (let i = 0; i < spells.length; i++) {
    const s = spells[i];
    const thr = Math.floor((success + s - 1) / s);
    const idx = lowerBound(thr);
    res[i] = m - idx;
  }
  return res;
};