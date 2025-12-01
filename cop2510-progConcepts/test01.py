class Student:
    def __init__(self, name):
        self._name = name

    def displayName(self):
        print(self._name)

s1 = Student("Santhosh")
s1.displayName()

# Raises an error
print(s1._name)