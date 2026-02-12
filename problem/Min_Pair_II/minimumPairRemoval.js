/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumPairRemoval = function(nums) {
    const n = nums.length;
    if (n <= 1) return 0;

    const arr = nums.slice();
    const removed = new Uint8Array(n); 
    const prev = new Int32Array(n);
    const next = new Int32Array(n);
    
    for (let i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }

    const pq = new MinPriorityQueue({ 
        compare: (a, b) => {
            if (a[0] !== b[0]) return a[0] - b[0];
            return a[1] - b[1];
        }
    });

    let sorted = 0;
    for (let i = 1; i < n; ++i) {
        pq.enqueue([arr[i - 1] + arr[i], i - 1]);
        if (arr[i] >= arr[i - 1]) sorted++;
    }

    if (sorted === n - 1) return 0;

    let rem = n;

    while (rem > 1) {
        const [sum, left] = pq.dequeue();
        const right = next[left];

        if (right >= n || removed[left] || removed[right] || arr[left] + arr[right] !== sum) {
            continue;
        }

        const pre = prev[left];
        const nxt = next[right];

        if (arr[left] <= arr[right]) sorted--;
        if (pre !== -1 && arr[pre] <= arr[left]) sorted--;
        if (nxt !== n && arr[right] <= arr[nxt]) sorted--;

        arr[left] += arr[right];
        removed[right] = 1;
        rem--;

        if (pre === -1) {
            prev[left] = -1;
        } else {
            pq.enqueue([arr[pre] + arr[left], pre]);
            if (arr[pre] <= arr[left]) sorted++;
        }

        if (nxt === n) {
            next[left] = n;
        } else {
            prev[nxt] = left;
            next[left] = nxt;
            pq.enqueue([arr[left] + arr[nxt], left]);
            if (arr[left] <= arr[nxt]) sorted++;
        }

        if (sorted === rem - 1) return n - rem;
    }

    return n;
};