/**
 * @param {number[]} nums
 * @return {number}
 */
const mod = 1000000007;

var specialTriplets = function (nums) {
  const M = 100001;
  const n = nums.length;

  const freq = new Int32Array(M);
  const prev = new Int32Array(M);

  for (let i = 0; i < n; i++) freq[nums[i]]++;

  let cnt = 0n;

  prev[nums[0]]++;

  for (let i = 1; i < n - 1; i++) {
    const x = nums[i];
    const x2 = x << 1;

    if (x2 < M) {
      const left = BigInt(prev[x2]);
      const right = BigInt(freq[x2] - prev[x2] - (x === 0 ? 1 : 0));
      cnt += left * right;
    }

    prev[x]++;
  }

  return Number(cnt % BigInt(mod));
};
