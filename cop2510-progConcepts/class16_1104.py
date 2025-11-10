#Intro to classes

class CreditAccount:
    #initializer
    def __init__(self, holder, limit, apr, balance):
        self.__holder = holder
        self.__limit = limit
        self.__apr = apr
        self.__balance = balance
       
    #Accessors (getters)
    def getHolder(self):
        return self.__holder
    def getLimit(self):
        return self.__limit
    def getAPR(self):
        return self.__apr
    def getBalance(self):
        return self.__balance


    #mutators (setters)
    def setHolder(self, hname):
        self.__holder = hname
    def setLimit(self, limit):
        self.__limit = limit
    def setApr(self, apr):
        self.__alr = apr
    def setBalance(self, balance):
        self.__balance = balance
       

    #additional methods
    def purchase(self, amount):
        self.__balance = self.__balance + amount

    def payment(self, amount):
        self.__balance = self.__balance - amount

    def apply_interest(self):
        rate = self.__apr / 12.0
        interest = self.__balance * rate
        self.__balance = self.__balance + interest
        return interest
       
       

    #string (summary) method
    def __str__(self):
        return (f'Credit Account Info:\n\tHolder: {self.__holder}'
                f'\n\tLimit: ${self.__limit:,.2f}'
                f'\n\tAPR: {self.__apr * 100:.2f}%'
                f'\n\tBalance: ${self.__balance:,.2f}')