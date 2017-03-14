#!/bin/python3

n = int(input())
power = 2 ** n
t = power * n
print(t)
for mask in range(power):
    for k in range(n):
        print(n, k)
        for i in range(n):
            print(1 if mask & (1<<i) else 0, end = '')
        print()