/**
 * @param {number[]} nums
 * @return {number[]}
 */
const constructTransformedArray = A => 
   A.map((v, i) => A.at((i + v) % A.length));