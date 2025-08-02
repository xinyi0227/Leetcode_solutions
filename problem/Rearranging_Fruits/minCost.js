/**
 * @param {number[]} basket1
 * @param {number[]} basket2
 * @return {number}
 */
var minCost = function(basket1, basket2) {
    const totalCounts = new Map();
    let minVal = Infinity;
    for (let fruit of basket1) {
        totalCounts.set(fruit, (totalCounts.get(fruit) || 0) + 1);
        minVal = Math.min(minVal, fruit);
    }
    for (let fruit of basket2) {
        totalCounts.set(fruit, (totalCounts.get(fruit) || 0) + 1);
        minVal = Math.min(minVal, fruit);
    }

    for (let [fruit, count] of totalCounts.entries()) {
        if (count % 2 !== 0) return -1;
    }

    const count1 = new Map();
    for (let fruit of basket1) {
        count1.set(fruit, (count1.get(fruit) || 0) + 1);
    }

    const swaps = [];
    for (let [fruit, total] of totalCounts.entries()) {
        let diff = (count1.get(fruit) || 0) - total / 2;
        for (let i = 0; i < Math.abs(diff); i++)
            swaps.push(fruit);
    }

    swaps.sort((a, b) => a - b);
    let totalCost = 0;
    let swapsToMake = swaps.length / 2;
    for (let i = 0; i < swapsToMake; ++i) {
        totalCost += Math.min(swaps[i], 2 * minVal);
    }
    return totalCost;
};
