/**
 * @param {number[]} values
 * @return {number}
 */
var minScoreTriangulation = function(v) {
    let n = v.length;
    let dp = Array.from({length:n}, ()=>Array(n).fill(0));
    
    for (let len=3; len<=n; len++) {
        for (let i=0; i+len-1<n; i++) {
            let j = i+len-1;
            dp[i][j] = Infinity;
            for (let k=i+1; k<j; k++) {
                dp[i][j] = Math.min(dp[i][j],
                    dp[i][k] + dp[k][j] + v[i]*v[j]*v[k]);
            }
        }
    }
    return dp[0][n-1];
};