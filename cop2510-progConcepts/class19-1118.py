# Multiple Inheritance
# parent classes
class Animal:
    def __init__(self, name):
        print(f'{name} is an animal.')
        # super().__init__(name)

class HatesWaterBaths:
    def __init__(self, name):
        print(f'{name} hates getting a water bath.')
        # super().__init__(name)

class LoveSunBaths:
    def __init__(self, name):
        print(f'{name} loves laying in the sun.')
        # super().__init__(name) # if we put a super reference in the last parent, we will run into an error

# child class
class Cat(Animal, HatesWaterBaths, LoveSunBaths):
    def __init__(self, name):
        print(f'{name} is a cat.')
        # super().__init__(name) # the super reference is calling the first parent in the list
        # super().__init__(name)
        Animal.__init__(self, name) # the self is already part of the super reference

# ---- end class definitions -----
cat = Cat('Pandemica')

