#!/bin/python3

import sys

def getMagicNumber(s, k, b, m):
    a = list(map(int, s))
    n = len(a)
    ans = 0
    cur = 0
    mul = pow(b, k, m)
    for i in range(n):
        cur = (cur * b + a[i]) % m
        if i >= k:
            cur -= mul * a[i-k] % m
            cur %= m
            if cur < 0:
                cur += m
        if i >= k-1:
            ans += cur
    return ans

s = input().strip()
k, b, m = input().strip().split(' ')
k, b, m = [int(k), int(b), int(m)]
result = getMagicNumber(s, k, b, m)
print(result)
