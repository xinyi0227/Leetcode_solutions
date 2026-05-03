import java.util.*;

class Solution {
    private long[][] dp;

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        Collections.sort(robot);
        Arrays.sort(factory, (a, b) -> Integer.compare(a[0], b[0]));

        int n = robot.size();
        int m = factory.length;
        dp = new long[n][m];
        for (long[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(0, 0, robot, factory);
    }

    private long solve(int i, int j, List<Integer> robot, int[][] factory) {
        int n = robot.size();
        int m = factory.length;

        if (i == n) return 0;
        if (j == m) return (long) 1e15;
        if (dp[i][j] != -1) return dp[i][j];

        long res = solve(i, j + 1, robot, factory);

        long cost = 0;
        int pos = factory[j][0];
        int limit = factory[j][1];

        for (int k = 0; k < limit && i + k < n; k++) {
            cost += Math.abs((long) robot.get(i + k) - pos);
            long subproblem = solve(i + k + 1, j + 1, robot, factory);
            if (subproblem != (long) 1e15) {
                res = Math.min(res, cost + subproblem);
            }
        }

        return dp[i][j] = res;
    }
}