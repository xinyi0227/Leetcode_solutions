/**
 * @param {number[]} robot
 * @param {number[][]} factory
 * @return {number}
 */
var minimumTotalDistance = function(robot, factory) {
    robot.sort((a, b) => a - b);
    factory.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

    const n = robot.length;
    const m = factory.length;
    const dp = Array.from({ length: n }, () => Array(m).fill(-1));

    const solve = (i, j) => {
        if (i === n) return 0;
        if (j === m) return 1e15;
        if (dp[i][j] !== -1) return dp[i][j];

        let res = solve(i, j + 1);
        let cost = 0;
        const pos = factory[j][0];
        const limit = factory[j][1];

        for (let k = 0; k < limit && i + k < n; k++) {
            cost += Math.abs(robot[i + k] - pos);
            res = Math.min(res, cost + solve(i + k + 1, j + 1));
        }

        return dp[i][j] = res;
    };

    return solve(0, 0);
};