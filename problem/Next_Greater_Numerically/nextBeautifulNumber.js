/**
 * @param {number} n
 * @return {number}
 */
var nextBeautifulNumber = function(n) {
    const list = [];
    
    function isBeautiful(count) {
        for (let d = 1; d <= 7; d++) {
            if (count[d] !== 0 && count[d] !== d) return false;
        }
        return true;
    }

    function generate(num, count) {
        if (num > 0 && isBeautiful(count)) list.push(num);
        if (num > 1224444) return;

        for (let d = 1; d <= 7; d++) {
            if (count[d] < d) {
                count[d]++;
                generate(num * 10 + d, count);
                count[d]--;
            }
        }
    }

    generate(0, Array(10).fill(0));
    list.sort((a,b)=>a-b);
    for (let num of list) {
        if (num > n) return num;
    }
    return -1;
};