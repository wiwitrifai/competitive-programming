#!/bin/env python3
t = int(input())
for _ in range(t):
    s = input()
    cnt = [ 0 for i in range(26) ]
    n = len(s)
    for c in s:
        cnt[ord(c)-ord('A')] += 1
    cnt.sort(reverse=True)
    ans = n
    for k in range(1, 27):
        if n % k:
            continue
        v = n//k
        cur = sum(min(x, v) for x in cnt[:k])
        ans = min(ans, n - cur)
    print(ans)