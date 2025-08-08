/**
 * @param {number} n
 * @return {number}
 */
var soupServings = function(n) {
    if (n > 4800) return 1.0;
    const dp = Array.from({length: n + 1}, () => Array(n + 1).fill(-1));
    function f(a, b) {
        if (a <= 0 && b > 0) return 1.0;
        if (a == 0 && b == 0) return 0.5;
        if (a > 0 && b <= 0) return 0.0;
        if (a <= 0 && b <= 0) return 0.5;
        if (dp[a][b] !== -1) return dp[a][b];
        let x = 0.25 * f(a - 100, b);
        let y = 0.25 * f(a - 75, b - 25);
        let z = 0.25 * f(a - 50, b - 50);
        let w = 0.25 * f(a - 25, b - 75);
        return dp[a][b] = x + y + z + w;
    }
    return f(n, n);
};
