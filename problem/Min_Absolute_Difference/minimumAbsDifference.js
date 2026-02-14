/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {
    arr.sort((a, b) => a - b);
    let minDiff = Infinity;
    let res = [];

    for (let i = 1; i < arr.length; i++) {
        let diff = arr[i] - arr[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            res = [[arr[i - 1], arr[i]]];
        } else if (diff === minDiff) {
            res.push([arr[i - 1], arr[i]]);
        }
    }
    return res;
};