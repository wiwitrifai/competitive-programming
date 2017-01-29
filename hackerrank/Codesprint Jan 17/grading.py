#!/bin/python3

import sys


n = int(input().strip())
for a0 in range(n):
    grade = int(input().strip())
    if grade>=38:
        if (grade//5+1) * 5 - grade < 3:
            grade = 5 * (grade//5 + 1)
    print(grade)
