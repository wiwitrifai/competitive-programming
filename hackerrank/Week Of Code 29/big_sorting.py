#!/bin/python3

a = [int(input().strip()) for _ in range(int(input().strip()))]
a.sort()
print('\n'.join(map(str, a)))