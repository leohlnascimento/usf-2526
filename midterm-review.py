'''
# print statement
number = int(input("say a number: "))
print(2, 3, 895, sep="------", end=' I\'m happy')
print()

# for loops
for i in range(80, number, -10):
    print(i)

# while loops
while i in range(50):
    print(i)
    i *= 5
'''

'''
# input validation
# boolean type : True or False
# a < b

# while my user does the dumb thing of not writing a number, ask him again
while True:
    try:
        number = int(input("type a number between 2 and 10: "))
        if 2 <= number <= 10:
            break
        else:
            print("between 2 and 10.")
    except ValueError:
        print("invalid type")
'''

'''
# tuple, match case, enumerate
number = 1.2458
print(f"{number:,.2f}")
a, b = (1, 2)
print(a)
print(b)
n = int(input("type n: "))
match n:
    case 0:
        print("zero")
    case 1:
        print("one")
    case 2:
        print("two")

lista1 = ["a", "b", "c"]
for key, value in enumerate(lista1):
    print(key, value)
'''

'''
for g in range(10, 70, 5):
    if g // 5 == 4:
        continue
    if g // 9 == 5:
        break
    print(g, end='| ')
else:
    print(g-6, end='? ')


i = 25.1288
print(format(i, ".3f"))
'''
'''
# functions
def main():
    number = int(input())
    print(fact(number))

def fact(n:int):
    if n == 0 or n == 1:
        return 1
    else:
        return n * fact(n-1)

main()
'''

'''
# Exercise 01
# Value Swap
num1:int = int(input("Please enter your first integer: "))
num2:int = int(input("Please enter your second integer: "))
print("The values in num1 and num2 before the swap are:")
print(f"num1 = {num1} and num2 = {num2}")
num1 = num1 + num2
num2 = num1 - num2
num1 = num1 - num2
print("The values in num1 and num2 after the swap are:")
print(f"num1 = {num1} and num2 = {num2}")
'''
'''
# Runway Length
v:float = float(input("Enter the plane's take off speed in m/s: "))
a:float = float(input("Enter the plane's acceleration in m/s**2: "))
print(f"The minimum runway length needed for this airplane is {(v**2 / (2*a)) :.4f} meters")
'''
'''# Restaurant Selector
restaurants = {"Council Oak Steaks and Seafood": (False, False, False),
               "Wood Fired Pizza Wine Bar": (True, False, True),
               "Villaggio’s Ristorante Italiano": (True, False, False),
               "Farmacy Vegan Kitchen": (True, True, True)}
getinput = input("Is anyone in your party a vegetarian? ").lower()
vegetarian = (getinput == "yes")
getinput = input("Is anyone in your party a vegan? ").lower()
vegan = (getinput == "yes")
getinput = input("Is anyone in your party gluten free? ").lower()
glutenfree = (getinput == "yes")
print("Here are your restaurant choices:")
for r in restaurants:
    if vegetarian and not (restaurants[r][0]):
        continue
    if vegan and not (restaurants[r][1]):
        continue
    if glutenfree and not (restaurants[r][2]):
        continue
    print(r)
    '''
