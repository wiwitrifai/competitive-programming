#!/bin/python3

N = 10 ** 7 + 5
euler = [i for i in range(N)]
for p in range(2, N):
    if euler[p] != p: continue
    for x in range(p, N, p):
        euler[x] -= euler[x]//p

def solve(x, k, m):
    if m == 1:
        return 0
    if k == 1:
        return x % m
    return pow(x, solve(x, k-1, euler[m]), m)

for _ in range(int(input())):
    x, k, m = map(int, input().split())
    print(solve(x, k, m))