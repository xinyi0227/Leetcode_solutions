class Spreadsheet {
  constructor(rows) {
    this.mpp = new Map();
  }
  setCell(cell, value) {
    this.mpp.set(cell, value);
  }
  resetCell(cell) {
    this.mpp.set(cell, 0);
  }
  getValue(s) {
    s = s.substring(1);
    for (let i = 0; i < s.length; i++) {
      if (s[i] === '+') {
        const s1 = s.slice(0, i), s2 = s.slice(i + 1);
        const left = s1[0] >= 'A' && s1[0] <= 'Z' ? (this.mpp.get(s1) ?? 0) : parseInt(s1, 10);
        const right = s2[0] >= 'A' && s2[0] <= 'Z' ? (this.mpp.get(s2) ?? 0) : parseInt(s2, 10);
        return left + right;
      }
    }
    return 0;
  }
}
