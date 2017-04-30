#!/bin/python3

import sys

def minimumDeletions(n, a):
    if n <= 1: return 0
    inc = a[0] > a[1]
    ans = 0
    for i in range(1, n):
        cur = a[i] > a[i-1]
        ans += cur == inc
        inc = cur
    return ans

n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
# Return the minimum number of elements to delete to make the array zigzag
result = minimumDeletions(n, a)
print(result)
