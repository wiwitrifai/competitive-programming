#!/bin/python3

from math import log

n = int(input())
a = list(map(int, input().split()))
val = 0
for x in a:
    val += log(x)
l, r = 1, max(a) + 1
while l < r:
    m = (l+r)//2
    if (n * log(m) > val):
        r = m
    else:
        l = m+1
print(l)
