/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var minOperations = function(s, k) {
    let zero = 0;
    let len = s.length;

    for (let i = 0; i < len; i++)
        zero += ~s.charCodeAt(i) & 1;

    if (!zero)
        return 0;

    if (len === k)
        return ((zero === len ? 1 : 0) << 1) - 1;

    let base = len - k;

    let odd = Math.max(
        Math.floor((zero + k - 1) / k),
        Math.floor((len - zero + base - 1) / base)
    );
    odd += ~odd & 1;

    let even = Math.max(
        Math.floor((zero + k - 1) / k),
        Math.floor((zero + base - 1) / base)
    );
    even += even & 1;

    let res = Infinity;

    if ((k & 1) === (zero & 1))
        res = Math.min(res, odd);

    if (~zero & 1)
        res = Math.min(res, even);

    return res === Infinity ? -1 : res;
};