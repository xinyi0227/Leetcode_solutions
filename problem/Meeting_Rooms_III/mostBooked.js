/**
 * @param {number} n
 * @param {number[][]} meetings
 * @return {number}
 */
var mostBooked = function(n, meetings) {
    let ans = Array(n).fill(0);
    let times = Array(n).fill(0);

    meetings.sort((a, b) => (a[0] - b[0]) || (a[1] - b[1]));

    for (let i = 0; i < meetings.length; i++) {
        let start = meetings[i][0], end = meetings[i][1];
        let flag = false;
        let minind = -1;
        let val = Number.POSITIVE_INFINITY;

        for (let j = 0; j < n; j++) {
            if (times[j] < val) {
                val = times[j];
                minind = j;
            }
            if (times[j] <= start) {
                flag = true;
                ans[j]++;
                times[j] = end;
                break;
            }
        }

        if (!flag) {
            ans[minind]++;
            times[minind] += (end - start);
        }
    }

    let maxi = -1, id = -1;
    for (let i = 0; i < n; i++) {
        if (ans[i] > maxi) {
            maxi = ans[i];
            id = i;
        }
    }
    return id;
};