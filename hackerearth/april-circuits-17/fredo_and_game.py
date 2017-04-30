#!/bin/python3

for _ in range(int(input())):
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    i = 0
    while i < n and k > 0:
        k += a[i] * 3 - 1
        i += 1
    if i == n:
        print('Yes', k)
    else:
        print('No', i)