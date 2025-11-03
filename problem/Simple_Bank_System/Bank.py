class Bank:
    def __init__(self, balance):
        self.bal = balance
        self.n = len(balance)

    def valid(self, acc):
        return 1 <= acc <= self.n

    def transfer(self, account1, account2, money):
        if not self.valid(account1) or not self.valid(account2) or self.bal[account1 - 1] < money:
            return False
        self.bal[account1 - 1] -= money
        self.bal[account2 - 1] += money
        return True

    def deposit(self, account, money):
        if not self.valid(account):
            return False
        self.bal[account - 1] += money
        return True

    def withdraw(self, account, money):
        if not self.valid(account) or self.bal[account - 1] < money:
            return False
        self.bal[account - 1] -= money
        return True