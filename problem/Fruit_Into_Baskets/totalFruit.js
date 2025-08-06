/**
 * @param {number[]} fruits
 * @return {number}
 */
var totalFruit = function(fruits) {
    let n = fruits.length;
    let ans = 0;
    let basket = [-1, -1], cnt = [0, 0];
    let lastRun = 0;
    
    for (let i = 0; i < n; i++) {
        let x = fruits[i];
        if (x === basket[1]) {
            cnt[1]++;
            lastRun++;
        } 
        else if (x === basket[0]) {
            [basket[0], basket[1]] = [basket[1], basket[0]];
            [cnt[0], cnt[1]] = [cnt[1], cnt[0]];
            cnt[1]++;
            lastRun = 1;
        } 
        else {
            basket[0] = basket[1];
            basket[1] = x;
            cnt[0] = lastRun;
            lastRun = 1;
            cnt[1] = 1;
        }
        ans = Math.max(ans, cnt[0] + cnt[1]);
    }
    return ans;
};
