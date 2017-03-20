#!/bin/python3

n,t = input().strip().split(' ')
n,t = [int(n),int(t)]
c = list(map(int, input().strip().split(' ')))

ans = 0
cur = n
for i in range(t):
    cur -= c[i]
    if cur < 5 and i < t-1:
        ans += n-cur
        cur = n
print(ans)