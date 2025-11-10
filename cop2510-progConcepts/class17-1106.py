#Driver program
from class16_1104 import CreditAccount

#create object (test init method)

acct1 = CreditAccount('John Doe', 10000, 0.24, 1000)

#test str method
print(acct1)


print(acct1.getLimit()) #accessor test
acct1.setLimit(1500)
print(acct1)

#test making a purchase
amt = float(input('Purchase amount: $'))
acct1.purchase(amt)
print('Purchase recorded')

amt2 = float(input('Payment amount: $'))
acct1.payment(amt2)
print('Payment recorded')


#test monthly interest
interest = acct1.apply_interest()
print(f'Interest applied: ${interest:.2f}')

#summary
print(f'\nFinal state: \n{acct1}')


# list of objects
# input validation / type checking
accounts = []
valid = False
while not valid:
    try:
        numaccts = int(input('How many accounts to create? '))
        if numaccts > 0:
            valid = True
        else:
            print('Enter a positive number. ')
    except ValueError:
        print('Enter a whole number.')
#create numaccounts number of accounts
for n in range(numaccts):
    print(f'\n---Enter details for account #{n + 1}---')
    holder = input('Aaccount Holder name: ')
    limit = float(input('Credit Limit: $'))
    apr = float(input('APR (as a decimal): '))
    balance = float(input('Balance: $'))
    acct = CreditAccount(holder, limit, apr, balance)
    accounts.append(acct)

#Show all accounts
print('\n----Accounts created----')
for a in accounts:
    print(a)


# use of matplotlib
import matplotlib.pyplot as plt

# sample data
exams = [1, 2, 3, 4, 5]
scores = [78, 85, 88, 92, 94]

# create line graph
plt.plot(exams, scores)

plt.show()