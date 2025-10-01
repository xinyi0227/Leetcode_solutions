/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function(numBottles, numExchange) {
    let drinked = 0, eb = 0;
    while (numBottles > 0) {
        drinked += numBottles;
        eb += numBottles;
        numBottles = Math.floor(eb / numExchange);
        eb = eb % numExchange;
    }
    return drinked;
};
