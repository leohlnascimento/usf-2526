# file input
dobj = open('reminder.txt', 'r')
breeds = dobj.read()
dobj.close()
# print(breeds)

with open('reminder.txt', 'r') as d2:
    doglist = d2.readlines()
# print(doglist)
# clean up the list
doglist2 = [d.rstrip() for d in doglist]
# print(doglist2)
# print(doglist2[0])
# .read() returns a string, .readlines() return a list (both including the formatting)
# .rstrip() removes the whitespace (by default)

# read one line
with open('reminder.txt') as d3:
    dog = d3.readline()
    print(dog)

# read the contents using readline() -> one line at a time
with open('reminder.txt') as d3:
    while True:
        dog = d3.readline()
        print(dog)
        if not dog:
            break