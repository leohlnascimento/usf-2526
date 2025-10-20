# add lists, joins lists togethe
# [1, 2, 3, 4,] + [5, canada] = [1, 2, 3, 4, 5, canada]
# This works with multiplication as well
# You CAN combine/multiply tuples (11, 13) + (17, 19) = (11, 13, 17, 19)
#this does NOT work on sets and dictionaries
# THIS WILL APPEAR ON EXAM

##print (len('Lance')) #Len will count the number of items. Works with strings, sets, tuples, lists, ect.
##
##list1 = [1, 2, 3, 3, 4, 5, 5, 7, 6,]
##set1 = set(list1) #converts list to set, gets rid of duplicates
##tuple1 = tuple(list1) # converts list to tuple
##list2 = list(list1) # converts into list
##set1.discard(2)
##print (set1)

#import modules
import math, random #imports the entire math module and ramdom module
sq = math.sqrt(25)
print (sq)
rn = random.randint(1, 6)
 #import a method from the module
from math import trunc, floor
f = floor(3.4); print (f)
#beneficial because you dont have to specify the module with every method

# use as to rename a method or module
from random import random as rand
print(rand())


#THIS ONE IS ON THE EXAM:
#warning: be careful using this *
# * is a wild card
from math import *  #* imports all the methods, * can import a lot of methods you may not use

    #THIS IS ALSO ON THE EXAM:
#membership vs identity (vs equality)
    #membership: in, not in
name = 'lance'
print('c' in name) #basically asking if there is a 'c' in name, will display true or false
print('u' not in name)
    #Identity: is, is not
m = 10
n = m #binding m and n to the same object
print(m is n) #gave True because m and n are the same object
print(m == n) #gave True because m and n are the same value

p = 2000
p /= m ** 2 * 2
print(m is p) # gave false
print(m == n) # gave true

#relational operators
# ==, !=, <, >, <=, >=