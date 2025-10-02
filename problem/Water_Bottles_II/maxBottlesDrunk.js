/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var maxBottlesDrunk = function(numBottles, numExchange) {
    let bottleDrunk = numBottles;
    let emptyBottles = numBottles;
    
    while (emptyBottles >= numExchange) {
        emptyBottles -= numExchange;
        numExchange++;
        bottleDrunk++;
        emptyBottles++;
    }
    
    return bottleDrunk;
};
