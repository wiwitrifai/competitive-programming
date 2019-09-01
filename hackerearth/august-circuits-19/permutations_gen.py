N = 10 ** 5
M = 2 * 10 ** 5

from random import randint

print(N)
print(' '.join(map(str, [randint(0, N) for _ in range(N)])))
print(M)
for i in range(M):
    t = randint(1, 3)
    if t == 1:
        x, y = randint(1, N+1), randint(1, N+1)
        print(t, x, y)
    else:
        l, r, k = randint(1, N+1), randint(1, N+1), randint(1, N+1)
        if l > r:
            l, r = r, l
        print(t, l, r, k)
