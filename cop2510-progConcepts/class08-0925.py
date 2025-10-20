newscore = float(input('Enter a score (0-100): '))
#input validation
# The while loop will run as long as the condition is true, will terminate when false
while newscore < 0 or newscore > 100:
    newscore = float(input('Invalid. Enter a score (0-100): '))
if newscore >= 90:
    grade = 'A'
else:
    if newscore >= 80:
        grade = 'B'
    else:
        if newscore >= 70:
            grade = 'C'
        else:
            if newscore >= 60:
                grade = 'D'
            else:
                if newscore <= 60:
                    grade = 'F'
print(grade)

#elif combines if and else
if newscore >=90:
    grade = 'A'
elif newscore >=80:
    grade = 'B'
elif newscore >=70:
    grade = 'C'

#series of if statements
#elif combines if and else
if newscore >=90:
    grade = 'A'
if newscore >=80:
    grade = 'B'
if newscore >=70:
    grade = 'C'
if newscore >=60:
    grade = 'D'
if newscore <60:
    grade = 'F'
#if a 84 is entered, grade will be D, because 84 >= 60.
#if you want this to work, must define full range 
                
if newscore >=90:
    if newscore <= 100:
        grade = 'A' #this is one method for defining range
if newscore >=80 and newscore < 90:
    grade = 'B' #this is another method for defining range
if 70 <= newscore < 80:
    grade = 'C' #this is a third method for defining range
if newscore in range(60, 70): 
    grade = 'D' #fourth method, lower limit is incluse and upper is exclusive
if newscore <60:
    grade = 'F'
print(f'The grade for a score of {newscore} is {grade}.')

#match case
score = int(newscore)
match score // 10:
    case 9 | 10: # purpose of | is to combine cases that have same outcome
        grade = 'A'
    case 8:
        grade = 'B'
    case 7:
        grade = 'C'
    case 6:
        grade = 'D'
    case _: #default (wildcard) - same as trailing else
        grade = 'F'
print (f'The grade for a score of {score} is {grade}')

# input validation with walrus operator
while (number := int(input('Enter positive number: '))) <0:
    print('Invalid number.')

#count controlled while loop
i = 1
while i <= 5:
    print(i)
    i += 1 #update statement
#This will run 5 times


#for loop
for j in range (1, 6):
    print (j)