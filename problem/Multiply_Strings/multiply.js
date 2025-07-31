/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
function multiply(num1, num2) {
    let n1 = num1.length, n2 = num2.length;
    let num = new Array(n1 + n2).fill(0);

    for (let i = n1 -1; i >= 0; i--) {
        for (let j = n2 -1; j >= 0; j--) {
            let mul = (num1.charCodeAt(i) - 48) * (num2.charCodeAt(j) - 48);
            let sum = num[i + j + 1] + mul;
            num[i + j + 1] = sum % 10;
            num[i + j] += Math.floor(sum / 10);
        }
    }

    while (num.length > 1 && num[0] === 0) {
        num.shift();
    }

    return num.join('');
}
