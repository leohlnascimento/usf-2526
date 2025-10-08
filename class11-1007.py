# Week 7 Lecture 1
# Example with named tuples and functions!

from collections import namedtuple
MenuIte = namedtuple("MenuItem", ["id", "name", "price"])
Menu = [MenuIte(1, 'strawberry', 1.25),
        MenuIte(2, 'mango', 1.50),
        MenuIte(3, 'banana', 0.95)]
# print(MenuIte)
# print(menu)
# print(menu[1])
# print(menu[1].name)

# ---- begin function definitions ----
def show_menu(menu):
    print('menu (press 0 if done:)')
    for item in menu:
        print(f'{item.id}. {item.name:_>15} ${item.price:.2f}')

def pick_ing(m):
    chosen = []
    choice = -1 # sentinel (stop loop)
    while choice != 0:
        # get user input
        while True:
            try:
                choice = int(input())
                if 1 <= choice <= 3:
                    break
                else:
                    print("choose valid option")
            except ValueError:
                print("invalid value")

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
            # qty = get more input
            # for loop to build the list

    return chosen # return a list

def main():
    # in python, all function return values
    print('Welcome to the Smoothie Bar!')
    show_menu(Menu)
    # ingredients = pick_ing(Menu)
    return 0

# ---- end of function definitions ----
main()