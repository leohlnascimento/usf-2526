'''
# use of integer division and remainder
print(f'86 seconds is equivalent to {86/60} minutes')
print(f'86 seconds is equivalent to {86//60} minute(s) and {86%60} seconds.')

#operator precedents ( general rules and generation for mathematical operations)
# ()
# **
# /, //, %, *  from left to right
# +, -
# =

#recap : initialization
a = 10

#updates to the same variable
a = a + 5 #equivalent to a + = 5 (using compund assignment)
print(a)

#compound assignment +=, -=, *=, /=, //=, %=, **=
a += 15 #a = a + (15)
print(a)

b = 2
a *= b + 4 # a = a* (b+4) = 30 * (2 +4) = 30 * 6 = 180 (compound assignment will always have parenthesis on the right hand side of the equation
print(a)

#percent formatting
rate = 0.3
print(f'{rate:%}') #format a decimal to percentage
print(f'{rate:.0%}')# no decimal places
'''

#input - default type is string
num1 = input('Enter an integer: ')
num2 = input('Enter another integer: ')
print(f'{num1}+ {num2} = {num1 + num2} ') # string concatenation

num1 = int(input('Enter an integer: '))
num2 = float(input('Enter a floating point number: '))
print(f'{num1}+ {num2} = {num1 + num2} ') # arithmetic
