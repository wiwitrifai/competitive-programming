#!/bin/python3

import sys

def getArrayKb(n, d):
    ans = 4
    for v in d:
        ans *= v
    ans = ans//1024
    return ans
    # Complete this function

#  Return the size of the multidimensional array in kilobytes. Return only the integer part.
n = int(input().strip())
d = list(map(int, input().strip().split(' ')))
result = getArrayKb(n, d)
print(result)