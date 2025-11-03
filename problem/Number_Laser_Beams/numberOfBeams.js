/**
 * @param {string[]} bank
 * @return {number}
 */
var numberOfBeams = function(bank) {
    if (bank.length === 0) return 0;
    let sd = [];
    for (let row of bank) {
        let count = 0;
        for (let i = 0; i < row.length; i++) {
            if (row[i] === '1') count++;
        }
        sd.push(count);
    }
    let sdwz = [];
    for (let i = 0; i < sd.length; i++) {
        if (sd[i] !== 0) {
            sdwz.push(sd[i]);
        }
    }
    let ans = 0;
    if (sdwz.length <= 1) return ans;
    for (let i = 0; i < sdwz.length - 1; i++) {
        ans += sdwz[i] * sdwz[i + 1];
    }
    return ans;
};