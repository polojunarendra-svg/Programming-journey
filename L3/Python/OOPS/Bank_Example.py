class Demo:
    def __init__(self,money):
        self.money = money
    def deposite(self,temp):
        if temp>0:
            self.money=self.money+temp
        return self.money
    def withdraw(self,temp):
        if temp>0:
            self.money=self.money-temp
        return self.money
    def deposit(self):
        print(self.money," Is currently in your bank account")
if __name__ == "__main__":
    d=Demo(15000)
    d.deposite(100)
    d.withdraw(50)
    d.deposit()