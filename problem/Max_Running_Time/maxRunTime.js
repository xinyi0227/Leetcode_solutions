/**
 * @param {number} n
 * @param {number[]} batteries
 * @return {number}
 */
var maxRunTime = function(n, A) {
    A.sort((a, b) => a - b);
    let sum = 0n;
    for (const x of A) sum += BigInt(x);
    let k = 0n;
    const na = BigInt(A.length);
    while (BigInt(A[Number(na - 1n - k)]) > sum / (BigInt(n) - k)) {
        sum -= BigInt(A[Number(na - 1n - k)]);
        k += 1n;
    }
    return Number(sum / (BigInt(n) - k));
};

