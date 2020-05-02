#!/bin/python3

def gets():
    return list(map(int, input().strip().split()))
n, m = gets()
f = []
for _ in range(2 * m + 1):
    f.append(gets())
g = []
for _ in range(n):
    g.append(gets())
res = [[0] * n for i in range(n)]
for i in range(n):
    for j in range(n):
        res[i][j] = 0
        for a in range(-m, m + 1):
            if i+a < 0 or i+a >= n: continue
            for b in range(-m, m + 1):
                if j+b < 0 or j+b >= n: continue
                res[i][j] += g[i+a][j+b] * f[a+m][b+m]
print('\n'.join(map(lambda x : ' '.join(map(str, x)), res)))