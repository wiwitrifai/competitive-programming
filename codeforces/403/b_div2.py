#!/bin/python3

n = int(input())
x = list(map(int, input().split()))
v = list(map(int, input().split()))
lo, hi = min(x), max(x)
def count(pos):
    ret = 0
    for i in range(n):
        ret = max(ret, abs(pos-x[i])/v[i])
    return ret
for _ in range(50):
    le, ri = (lo + lo + hi)/3, (lo + hi + hi)/3
    if count(le) < count(ri):
        hi = ri
    else:
        lo = le
print("%.13f" % count(lo))