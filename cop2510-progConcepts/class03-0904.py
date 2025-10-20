'''
    01. Tuples
        container that has immutable values

    02. Walrus operator :=
        initialize, assign, and print
    
    03. Multiple assignment and respective assignment
        x = y = 45
        a, b = 8.6, 3.5

    04. e-notation
        full = 67e6 # 67 million
        guaranteed = 44E6 # 44 million
        they always come as floats
'''

## MaxSeats = (152,)
## print(MaxSeats[0])
'''
print('The number of students in class on Tuesday was', \
      students := 99) # use \ to split a line of code

print(f'The number of students in class was \
      {students := 10}') # := generates a field width based on

print(f'The number of students in class was \
      {(students := 8)}')

print(f'The number of students in class was {(students := 7)}')
'''

'''
import turtle

t = turtle.Turtle()
t.pendown()
t.forward(100)
t.left(120)
t.forward(100)
t.left(120)
t.forward(100)
t.left(120)

turtle.done()
'''

a = float(input())
b = float(input())
c = float(input())
s = (a+b+c) / 2
area = (s*(s-a)*(s-b)*(s-c)) ** (1/2)
print(f"triangle area = {area:.2f}")