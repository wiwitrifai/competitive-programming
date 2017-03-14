#!/bin/python3
for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().strip().split()))
    y = list(map(int, input().strip().split()))
    a, b = 0, 0
    for i in range(n):
        if i & 1:
            a += x[i]
            b += y[i]
        else:
            a += y[i]
            b += x[i]
    print(min(a, b))