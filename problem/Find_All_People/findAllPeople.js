/**
 * @param {number} n
 * @param {number[][]} meetings
 * @param {number} firstPerson
 * @return {number[]}
 */
var findAllPeople = function(n, meetings, firstPerson) {
    const find = (groups, index) => {
        while (index !== groups[index]) {
            index = groups[index];
        }
        return index;
    };

    let groups = new Array(100000).fill(0).map((_, i) => i);
    let result = [];

    groups[firstPerson] = 0;

    meetings.sort((a, b) => a[2] - b[2]);

    let i = 0;
    while (i < meetings.length) {
        let currentTime = meetings[i][2];
        let temp = [];
        while (i < meetings.length && meetings[i][2] === currentTime) {
            let g1 = find(groups, meetings[i][0]);
            let g2 = find(groups, meetings[i][1]);
            groups[Math.max(g1, g2)] = Math.min(g1, g2);
            temp.push(meetings[i][0]);
            temp.push(meetings[i][1]);
            ++i;
        }
        for (let j = 0; j < temp.length; ++j) {
            if (find(groups, temp[j]) !== 0) {
                groups[temp[j]] = temp[j];
            }
        }
    }

    for (let j = 0; j < n; ++j) {
        if (find(groups, j) === 0) {
            result.push(j);
        }
    }

    return result;
};