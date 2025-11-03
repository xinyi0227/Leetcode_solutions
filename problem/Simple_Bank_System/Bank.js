var Bank = function(balance) {
    this.bal = balance;
    this.n = balance.length;
};

Bank.prototype.valid = function(acc) {
    return acc > 0 && acc <= this.n;
};

Bank.prototype.transfer = function(account1, account2, money) {
    if (!this.valid(account1) || !this.valid(account2) || this.bal[account1 - 1] < money)
        return false;
    this.bal[account1 - 1] -= money;
    this.bal[account2 - 1] += money;
    return true;
};

Bank.prototype.deposit = function(account, money) {
    if (!this.valid(account))
        return false;
    this.bal[account - 1] += money;
    return true;
};

Bank.prototype.withdraw = function(account, money) {
    if (!this.valid(account) || this.bal[account - 1] < money)
        return false;
    this.bal[account - 1] -= money;
    return true;
};