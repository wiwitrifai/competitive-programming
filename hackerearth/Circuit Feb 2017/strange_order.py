#!/bin/python3

n = int(input())

fac = [[] for _ in range(n+1)]
for i in range(2, n+1):
    if (len(fac[i]) > 0): continue
    for j in range(i, n+1, i):
        fac[j].append(i)

used = [False] * (n+1)
ans = []
for i in range(n, 1, -1):
    if used[i]: continue
    cur = []
    for f in fac[i]:
        if used[f]: continue
        for j in range(f, n+1, f):
            if not used[j]:
                used[j] = True
                cur.append(j)
    cur.sort(reverse = True)
    ans += cur
ans.append(1)
print(' '.join(map(str, ans)))