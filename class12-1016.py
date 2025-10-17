# Week 8 lecture 2
# import moduleClass12

# recursion
def greet(level):
    if level == 0: # base case
        print("Goodbye!")
    else:
        print(f"Hello from level {level}!")
        greet(level - 1)
        print(f"Back to level {level}!")

greet(3)

# recursion with return (w/ type hinting, annotation)
def recur_sum(n: int) -> int:
    if n==1: return 1
    else: return n + recur_sum(n-1)

print(recur_sum(3))

# annotation with lists
def multiples(v: float, a: int) -> list[float]:
    mult = []
    for i in range(1, a+1):
        mult.append(i ** v)
    return mult
print(multiples(2.32, 4))

# intro to lambda (small, anon) functions
test = lambda n: n+7
print(test(5))
# non-lambda function
def add7(n):
    return n+7
print(add7(4))