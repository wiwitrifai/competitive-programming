#!/bin/python3

n = int(input())
x = list(map(int, input().split()))
ans, cnt, used = 0, 0, [False] * (n + 1)
for v in x:
    if used[v]:
        cnt -= 1
    else:
        cnt += 1
        used[v] = True
    ans = max(ans, cnt)
print(ans)
