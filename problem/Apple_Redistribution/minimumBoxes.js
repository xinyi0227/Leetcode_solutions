/**
 * @param {number[]} apple
 * @param {number[]} capacity
 * @return {number}
 */
var minimumBoxes = function (apple, capacity) {
  let sum = 0;
  for (let i = 0; i < apple.length; i++) sum += apple[i];

  const freq = Array(51).fill(0);
  for (let i = 0; i < capacity.length; i++) freq[capacity[i]]++;

  let ans = 0;
  for (let c = 50; c >= 1; c--) {
    while (freq[c] > 0) {
      sum -= c;
      freq[c]--;
      ans++;
      if (sum <= 0) return ans;
    }
  }
  return ans;
};