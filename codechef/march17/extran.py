#!/bin/python3

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    a.sort()
    if a[0] + 1 != a[1] and a[0] + 1 != a[2]:
        print(a[0])
        continue
    ans = a[0]
    for i in range(1, n):
        if (a[i-1] + 1 != a[i]):
            ans = a[i]
    print(ans)