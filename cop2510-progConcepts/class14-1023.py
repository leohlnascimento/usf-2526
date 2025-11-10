# Week 9 Lecture 2

# list comprehension with if statement
list4 = [k+15 for k in range(10, 51, 10) if k<=30]
print(list4)

def teste(x):
    return x+5
teste(2)

# dictionary, set, tuple comprehension also exist!
# example of dictionary comprehension
students = [('Alice', 85),
            ('Bob', 70),
            ('Cara', 92),
            ('David', 87),
            ('Eli', 90)]
studentGrades = {name: ('A' if score >= 90 else 'B' if score >= 80 else 'C') 
                 for name, score in students}
print(studentGrades)

# string slicing
name = 'leo'
print(name[::])
print(name[::-1])

# file input/output
# write to a file
with open('reminder.txt', mode='w') as outfile:
     outfile.write('Update recitation session attendance.')
    
with open('reminder.txt', mode='a') as outfile:
     outfile.write('backslashnCheck grades on Canvas.')
# in a windows machine - change the backward slashes to forward slashes
# "/Users/sksmall/Desktop/Fall2025/COP2510/reminder.txt"
# write method overwrites your data

print("Writing to file complete.")
