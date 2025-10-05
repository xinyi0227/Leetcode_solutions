class TaskManager {
  constructor(tasks) {
    this.h = [];
    this.taskPriority = new Map();
    this.taskOwner = new Map();
    for (const t of tasks) this.add(t[0], t[1], t[2]);
  }
  _cmp(a, b) {
    if (a[0] !== b[0]) return a[0] > b[0];
    return a[1] > b[1];
  }
  _siftUp(i) {
    const a = this.h;
    while (i > 0) {
      const p = (i - 1) >> 1;
      if (this._cmp(a[p], a[i])) break;
      [a[p], a[i]] = [a[i], a[p]];
      i = p;
    }
  }
  _siftDown(i) {
    const a = this.h;
    const n = a.length;
    for (;;) {
      let l = (i << 1) + 1, r = l + 1, m = i;
      if (l < n && this._cmp(a[l], a[m])) m = l;
      if (r < n && this._cmp(a[r], a[m])) m = r;
      if (m === i) break;
      [a[i], a[m]] = [a[m], a[i]];
      i = m;
    }
  }
  _push(x) {
    this.h.push(x);
    this._siftUp(this.h.length - 1);
  }
  _pop() {
    const a = this.h;
    if (a.length === 0) return null;
    const top = a[0];
    const last = a.pop();
    if (a.length) {
      a[0] = last;
      this._siftDown(0);
    }
    return top;
  }
  add(userId, taskId, priority) {
    this._push([priority, taskId]);
    this.taskPriority.set(taskId, priority);
    this.taskOwner.set(taskId, userId);
  }
  edit(taskId, newPriority) {
    this._push([newPriority, taskId]);
    this.taskPriority.set(taskId, newPriority);
  }
  rmv(taskId) {
    this.taskPriority.set(taskId, -1);
  }
  execTop() {
    for (;;) {
      const t = this._pop();
      if (!t) return -1;
      const p = t[0], id = t[1];
      if ((this.taskPriority.get(id) ?? -1) === p) {
        this.taskPriority.set(id, -1);
        return this.taskOwner.get(id) ?? -1;
      }
    }
  }
}
