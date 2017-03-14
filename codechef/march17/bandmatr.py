#!/bin/python3

for _ in range(int(input())):
    n = int(input())
    zero = 0
    for i in range(n):
        for z in map(int, input().strip().split()):
            zero += z == 0
    for k in range(n):
        cnt = 0
        for i in range(n):
            cnt += max(0, i-k) + max(0, n-(i+k)-1)
        if cnt <= zero:
            print(k)
            break
