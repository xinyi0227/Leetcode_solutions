int64_t dp[2][15][2];
class Solution
{
public:
    static int maxProductPath(vector<vector<int>> &grid)
    {
        const int r = grid.size(), c = grid[0].size(), MOD = 1e9 + 7;
        int64_t p = dp[0][0][0] = dp[0][0][1] = grid[0][0];
        for (int j = 1; j < c; j++)
        {
            p *= grid[0][j];
            dp[0][j][0] = dp[0][j][1] = p;
        }
        p = grid[0][0];
        for (int i = 1; i < r; i++)
        {
            bool isOdd = i & 1, prv = !isOdd;
            p *= grid[i][0];
            dp[isOdd][0][0] = dp[isOdd][0][1] = p;
            for (int j = 1; j < c; j++)
            {
                int x = grid[i][j];
                auto [minP, maxP] = minmax({x * dp[isOdd][j - 1][0], x * dp[isOdd][j - 1][1], x * dp[prv][j][0], x * dp[prv][j][1]});
                dp[isOdd][j][0] = minP, dp[isOdd][j][1] = maxP;
            }
        }
        int64_t ans = dp[(r - 1) & 1][c - 1][1];
        return ans < 0 ? -1 : ans % MOD;
    }
};