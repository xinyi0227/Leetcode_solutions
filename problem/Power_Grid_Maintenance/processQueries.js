var processQueries = function(c, connections, queries) {
  class MinHeap {
    constructor(){ this.a = []; }
    empty(){ return this.a.length === 0; }
    top(){ return this.a[0]; }
    push(x){
      const a = this.a; a.push(x);
      let i = a.length - 1;
      while (i){
        const p = (i - 1) >> 1;
        if (a[p] <= a[i]) break;
        [a[p], a[i]] = [a[i], a[p]];
        i = p;
      }
    }
    pop(){
      const a = this.a;
      const n = a.length - 1;
      if (n < 0) return;
      if (n === 0){ a.pop(); return; }
      a[0] = a[n]; a.pop();
      let i = 0;
      while (true){
        let l = i*2 + 1, r = l + 1, b = i;
        if (l < a.length && a[l] < a[b]) b = l;
        if (r < a.length && a[r] < a[b]) b = r;
        if (b === i) break;
        [a[i], a[b]] = [a[b], a[i]];
        i = b;
      }
    }
  }

  const parent = Array.from({length: c}, (_, i) => i);
  const size = Array(c).fill(1);
  const offline = Array(c).fill(0);
  const heaps = Array.from({length: c}, () => new MinHeap());
  for (let i = 0; i < c; i++) heaps[i].push(i);

  const find = (x) => parent[x] === x ? x : (parent[x] = find(parent[x]));
  const mergeHeaps = (a, b) => { while (!b.empty()) a.push(b.top()), b.pop(); };
  const Union = (u, v) => {
    let up = find(u), vp = find(v);
    if (up === vp) return;
    if (size[up] > size[vp]) {
      size[up] += size[vp];
      parent[vp] = up;
      mergeHeaps(heaps[up], heaps[vp]);
    } else {
      size[vp] += size[up];
      parent[up] = vp;
      mergeHeaps(heaps[vp], heaps[up]);
    }
  };

  for (const [u0, v0] of connections) Union(u0 - 1, v0 - 1);

  const ans = [];
  for (const [type, node0] of queries) {
    const node = node0 - 1;
    if (type === 1) {
      if (offline[node] === 0) {
        ans.push(node + 1);
        continue;
      }
      const p = find(node);
      const h = heaps[p];
      while (!h.empty() && offline[h.top()] === 1) h.pop();
      if (h.empty()) {
        ans.push(-1);
      } else {
        ans.push(h.top() + 1);
      }
    } else {
      offline[node] = 1;
    }
  }
  return ans;
};