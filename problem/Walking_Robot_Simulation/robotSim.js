/**
 * @param {number[]} commands
 * @param {number[][]} obstacles
 * @return {number}
 */
var robotSim = function(commands, obstacles) {
    const blocked = new Set();
    for (const [ox, oy] of obstacles) {
        blocked.add(`${ox},${oy}`);
    }

    const dx = [0, 1, 0, -1];
    const dy = [1, 0, -1, 0];

    let x = 0, y = 0, dir = 0, maxDist = 0;

    for (const cmd of commands) {
        if (cmd === -1) {
            dir = (dir + 1) % 4;
        } else if (cmd === -2) {
            dir = (dir + 3) % 4;
        } else {
            for (let i = 0; i < cmd; i++) {
                const nx = x + dx[dir];
                const ny = y + dy[dir];

                if (blocked.has(`${nx},${ny}`)) break;

                x = nx;
                y = ny;
                maxDist = Math.max(maxDist, x * x + y * y);
            }
        }
    }

    return maxDist;
};