seq1 = [i for i in range(-3, 4)]
print(seq1)
seq2 = [(n * -10) if n<0 else n+15 for n in seq1]
print(seq2)
