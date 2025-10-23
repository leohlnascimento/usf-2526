# Recap: lambda function

cube = lambda v: v ** 3  # nameless function
# print(f"5 cubed is {cube(5)}")

# equals to
def cubeval(val):
    return val ** 3
# print(f"5 cubed is {cubeval(5)}")

# default parameter
def greet(name = 'Guest', greeting  = "Hello"):
    print(f"{greeting}, {name}!")
# greet('Alex', "Hello")
# greet('Maddy')
# greet()

# keyword arguments - make sure right values -> correct parameters
# greet(greeting='Howdy', name="leo")

def sum1(x):
    x = x + 1
    return x
y = 5
# print(sum1(y))
# print(y)

# print(print('no'))

# arbitraty argument
def calcsum(*numbers):
    total = 0
    print(type(numbers))
    for n in numbers:
        total += n
    return total
# print(calcsum(1, 2, 34))

# list comprehension - generate a new list from an existing one
list1 = [10, 20, 30, 40, 50]
list2 = [range(10, 51, 10)] # list2 = list(range(10, 51, 10))
list3 = [i for i in range(10, 51, 10)]
# print(list1)
# print(list2)
# print(list3)

# list comprehension w ternary statement
list4 = [j+7 if j<=30 else j+2 for j in range(10, 51, 10)]
print(list4)