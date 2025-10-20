# a = 65
# b = 14.0
# c = 34.3
# print(a in range(0, 100))
# print(b in range(0, 100))
# print(c in range(0, 100))

# num = int(input())
# print(int(num))

valid = False
while not valid:
    try:
        num = int(input())
        if num > 0:
            valid = True
        else:
            print("Enter a positive number")
    except ValueError:
        print("Incorrect value")


# for i in range(4, 1, -1):
#    print(i)

# what is the value for dividing by 0 ?
# what is the difference between one and two # comments?

abbr = {1: 'one', 2:'two'}

print(abbr[0])
