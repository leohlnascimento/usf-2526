# Week5 lecture 1

temp = int(input('Enter temperature: '))
rain = (input('Is it raining? (Y/N): '))
israin = False
print(temp, rain.upper(), israin)

if rain.upper() == 'Y':
    raining = True
if temp >= 65 and not raining:
    print('Go to the park.')
else:
    print('Watch TV.')

# ternary outcome
print("a" if temp<24 else "b")
print("a") if temp<34 else print("b")

# walrus operator
print("yay, you pass" if ((score := float(input('Enter score: ')))  >= 70) else 'try again')
print(score)

print(f"\{\}{score}")