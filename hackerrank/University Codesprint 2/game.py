#!/bin/python3

import sys


g = int(input().strip())
for a0 in range(g):
    n,m,x = input().strip().split(' ')
    n,m,x = [int(n),int(m),int(x)]
    a = list(map(int, input().strip().split(' ')))
    b = list(map(int, input().strip().split(' ')))
    suma, sumb = [0], [0]
    cur = 0
    for i in range(n):
        cur += a[i]
        suma.append(cur)
    cur = 0
    for i in range(m):
        cur += b[i]
        sumb.append(cur)
    j = m
    ans = 0
    for i in range(n+1):
        while j >= 0 and suma[i] + sumb[j] > x:
            j -= 1
        if j >= 0 and i + j > ans:
            ans = i + j
    print(ans)