/**
 * @param {string[]} wordlist
 * @param {string[]} queries
 * @return {string[]}
 */
var spellchecker = function(wordlist, queries) {
  const exact = new Set(wordlist);
  const caseMap = new Map();
  const vowelMap = new Map();
  const lower = s => s.toLowerCase();
  const devowel = s => s.toLowerCase().replace(/[aeiou]/g, '*');
  for (const w of wordlist) {
    const lw = lower(w);
    const dv = devowel(w);
    if (!caseMap.has(lw)) caseMap.set(lw, w);
    if (!vowelMap.has(dv)) vowelMap.set(dv, w);
  }
  const res = [];
  for (const q of queries) {
    if (exact.has(q)) { res.push(q); continue; }
    const lq = lower(q);
    if (caseMap.has(lq)) { res.push(caseMap.get(lq)); continue; }
    const dq = devowel(q);
    if (vowelMap.has(dq)) { res.push(vowelMap.get(dq)); continue; }
    res.push("");
  }
  return res;
};
