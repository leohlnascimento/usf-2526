# import turtle as t
# import random as r
# t.bgcolor("black")
# t.shape("turtle")
# t.speed(5) # max speed is 10

colors = ["red", "green", "blue"]

while True:
    try:
        numshapes = int(input())
        if 1 <= numshapes <= 10:
            break
        else:
            print("number between 1 and 10")
    except ValueError:
        print("Invalid entry")

'''
for i in range(numshapes):
    sides = r.randint(3, 8)
    size = r.randint(30, 100)
    t.color(r.choice(colors))

    # try to draw but break if it is too large
    for j in range(sides):
        if size > 90:
            print("skipping oversized shape.")
            break
        t.forward(size)
        t.left(360/sides)
    else:
        t.penup()
        t.goto(r.randint(-200, 200), r.randint(-200, 200))
        t.pendown()

t.done()
'''

# for i in range(3):
#     print(i, 1)
#     for j in range(3):
#         print(i, 2)

# will be on midterm, not an error
for j in range(1, 5):
    if j==2:
        break
    if j==4:
        print(4)
    else:
        print("oi")
else:
    print("ok",end='')