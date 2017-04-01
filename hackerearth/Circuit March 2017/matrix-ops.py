#!/bin/python3
from functools import cmp_to_key
def gets():
    return list(map(int, input().strip().split()))

n, m = gets()
a = [gets() for i in range(n)]
idx = [(i, j) for i in range(n) for j in range(n)]
def compare(le, ri):
    ret = (ri[0] + 1) * (ri[1] + 1) - (le[0] + 1) * (le[1] + 1)
    if ret != 0:
        return  ret
    return ri[0] - le[0]
idx.sort(key = cmp_to_key(compare))
sm = sum(sum(row) for row in a) - n * n
for i,j in idx:
    cur = min(sm, m-1)
    sm -= cur
    a[i][j] = 1 + cur
print('\n'.join(map(lambda x : ' '.join(map(str, x)), a)))