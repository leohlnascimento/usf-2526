# Week 7 Lecture 1
# Example with named tuples and functions!

from collections import namedtuple
MenuIte = namedtuple("MenuItem", ["id", "name", "price"])

TAX = 0.07
Menu = [MenuIte(1, 'strawberry', 1.25),
        MenuIte(2, 'mango', 1.50),
        MenuIte(3, 'banana', 0.95)]
# print(MenuIte)
# print(menu)
# print(menu[1])
# print(menu[1].name)

# ---- begin function definitions ----
def getinput(prompt:str, lo:int, hi:int):
    while True:
        try:
            n = int(input(prompt))
            if lo <= n <= hi:
                break
            else:
                print("choose valid option")
        except ValueError:
            print("invalid value")
    return n

def show_menu(menu):
    print('menu (press 0 if done:)')
    for item in menu:
        print(f'{item.id}. {item.name:_>15} ${item.price:.2f}')

def pick_ing(m):
    chosen = []
    choice = -1 # sentinel (stop loop)
    while choice != 0:
        choice = getinput("Choose id (0 if done): ", 0, 3)

        if choice == 0:
            if not chosen: # my list is empty
                print('Add at least one ingredient.')
                choice = -1 # stay in the loop
            else:
                break
        else:
            for i in m:
                if i.id == choice:
                    item = i
                    break
            qty = getinput("how many: ", 0, 3)
            for j in range(qty):
                chosen.append(item)
            print(f"added {qty} {item.name}(s)")
    return chosen # return a list

def totals(items):
    subtotal = 0
    for i in items:
        subtotal += i.price
    subtotal = round(subtotal, 2)
    tax = round(subtotal * TAX, 2)
    total = round(subtotal + tax, 2)
    return subtotal, tax, total # python does packing -> packs it in a tuple

def main():
    # in python, all function return values
    print('Welcome to the Smoothie Bar!')
    show_menu(Menu)
    ingredients = pick_ing(Menu)
    sub, tax, tot = totals(ingredients)
    print('-' * 25)
    print(f"your smoothie is going to cost ${sub}, before taxes. "
          f"after the 7% taxes of {tax} added, the total is {tot}")
    return 0

# ---- end of function definitions ----
main()