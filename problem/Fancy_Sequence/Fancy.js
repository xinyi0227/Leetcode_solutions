/**
 * @description Fancy sequence implementation using BigInt for precision
 * and modular inverse for O(1) updates.
 */
var Fancy = function() {
    this.mod = BigInt(10**9 + 7);
    this.values = [];
    this.a = 1n; 
    this.b = 0n; 
};

/** * Helper: Modular Exponentiation (Fast Power)
 * Computes (base^exp) % mod
 */
Fancy.prototype.power = function(base, exp) {
    let res = 1n;
    base %= this.mod;
    while (exp > 0n) {
        if (exp % 2n === 1n) res = (res * base) % this.mod;
        base = (base * base) % this.mod;
        exp /= 2n;
    }
    return res;
};

/** * Helper: Modular Inverse using Fermat's Little Theorem
 * Since mod is prime, a^(mod-2) % mod is the inverse.
 */
Fancy.prototype.modInverse = function(n) {
    return this.power(n, this.mod - 2n);
};

/** * @param {number} val
 * @return {void}
 */
Fancy.prototype.append = function(val) {
    let valBI = BigInt(val);
    let invA = this.modInverse(this.a);
    let x = ((valBI - this.b + this.mod) % this.mod * invA) % this.mod;
    this.values.push(x);
};

/** * @param {number} inc
 * @return {void}
 */
Fancy.prototype.addAll = function(inc) {
    this.b = (this.b + BigInt(inc)) % this.mod;
};

/** * @param {number} m
 * @return {void}
 */
Fancy.prototype.multAll = function(m) {
    let mBI = BigInt(m);
    this.a = (this.a * mBI) % this.mod;
    this.b = (this.b * mBI) % this.mod;
};

/** * @param {number} idx
 * @return {number}
 */
Fancy.prototype.getIndex = function(idx) {
    if (idx >= this.values.length) 
        return -1;
    let result = (this.a * this.values[idx] + this.b) % this.mod;
    return Number(result);
};