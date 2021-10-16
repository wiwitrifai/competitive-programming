from random import randint
n = 6
q = 20
maxV = 20
print(n, q)
a = [randint(1, maxV) for _ in range(n)]
print(' '.join(map(str, a)))
for i in range(q):
    op = 'FILCO'[randint(0, 4)]
    l = randint(1, n)
    r = randint(1, n)
    v = randint(1, maxV)
    if l > r:
        l, r = r, l
    if op == 'F':
        print(op, l, r, v)
    elif op == 'I':
        print(op, v)
    elif op == 'L':
        print(op, l, r)
    elif op == 'C':
        print(op, l, r)
    else:
        assert op == 'O'
        print(op, l, r)
