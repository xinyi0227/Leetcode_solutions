/**
 * @param {string} s
 * @return {number}
 */
function maxFreqSum(s) {
  const freq = Array(26).fill(0);
  let maxVowel = 0, maxConso = 0;
  for (const c of s) {
    const i = c.charCodeAt(0) - 97;
    if (i < 0 || i >= 26) continue;
    const v = ++freq[i];
    if (c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u') {
      if (v > maxVowel) maxVowel = v;
    } else {
      if (v > maxConso) maxConso = v;
    }
  }
  return maxVowel + maxConso;
}
