#!/bin/env python3
from sys import stderr
mod = 10 ** 9 + 7
for _ in range(int(input())):
    n, k, m = map(int, input().split())
    c = (m + 1) // 2
    f = (n-1) * pow(n, mod-2, mod) % mod
    ans = (1 - pow(f, c, mod)) % mod
    if (m & 1) == 0:
        ans = (ans + pow(f, c, mod) * pow(n+k, mod-2, mod)) % mod
    if ans < 0:
        ans += mod
    print(ans)