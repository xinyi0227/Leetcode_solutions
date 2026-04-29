/**
 * @param {string} word
 * @return {number}
 */
var minimumDistance = function(word) {
    const cal = (a, b) => {
        return Math.abs(Math.floor(a / 6) - Math.floor(b / 6)) + Math.abs((a % 6) - (b % 6));
    };

    let n = word.length;
    let dp = new Array(26).fill(0);

    for (let i = 1; i < n; i++) {
        let ndp = new Array(26);
        let p = word.charCodeAt(i - 1) - 65;
        let t = word.charCodeAt(i) - 65;

        for (let j = 0; j < 26; j++) {
            ndp[j] = dp[j] + cal(p, t);
        }
        for (let j = 0; j < 26; j++) {
            ndp[p] = Math.min(ndp[p], dp[j] + cal(j, t));
        }
        dp = ndp;
    }

    return Math.min(...dp);
};