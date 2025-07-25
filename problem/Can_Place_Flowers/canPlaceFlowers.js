/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function (flowerbed, n) {
    let len = flowerbed.length;
    for (let i = 0; i < len; i++) {
        let left = i === 0 || flowerbed[i - 1] === 0;
        let right = i === len - 1 || flowerbed[i + 1] === 0;

        if (left && right && flowerbed[i] === 0) {
            flowerbed[i] = 1;
            n--;
        }
    }
    return n <= 0;
};