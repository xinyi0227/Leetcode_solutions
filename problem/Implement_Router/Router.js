function lowerBound(arr, target, start) {
  let l = start, r = arr.length;
  while (l < r) {
    const m = (l + r) >> 1;
    if (arr[m] < target) l = m + 1;
    else r = m;
  }
  return l;
}

function upperBound(arr, target, start) {
  let l = start, r = arr.length;
  while (l < r) {
    const m = (l + r) >> 1;
    if (arr[m] <= target) l = m + 1;
    else r = m;
  }
  return l;
}

class Router {
  constructor(memoryLimit) {
    this.maxSize = memoryLimit;
    this.q = [];
    this.mpp = new Set();
    this.timestamps = new Map();
    this.st = new Map();
  }
  key(p) {
    return p[0] + "#" + p[1] + "#" + p[2];
  }
  addPacket(source, destination, timestamp) {
    const packet = [source, destination, timestamp];
    const k = this.key(packet);
    if (this.mpp.has(k)) return false;
    if (this.q.length === this.maxSize) {
      const res = this.q.shift();
      this.mpp.delete(this.key(res));
      const d = res[1];
      this.st.set(d, (this.st.get(d) || 0) + 1);
    }
    this.q.push(packet);
    this.mpp.add(k);
    if (!this.timestamps.has(destination)) this.timestamps.set(destination, []);
    this.timestamps.get(destination).push(timestamp);
    return true;
  }
  forwardPacket() {
    if (this.q.length === 0) return [];
    const res = this.q.shift();
    this.mpp.delete(this.key(res));
    const d = res[1];
    this.st.set(d, (this.st.get(d) || 0) + 1);
    return res;
  }
  getCount(destination, startTime, endTime) {
    const arr = this.timestamps.get(destination);
    if (!arr) return 0;
    const offset = Math.min(this.st.get(destination) || 0, arr.length);
    const l = lowerBound(arr, startTime, offset);
    const r = upperBound(arr, endTime, offset);
    return r - l;
  }
}
