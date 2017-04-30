#!/bin/python3

import sys

def getPoints(month1, month2, month3):
    return (min(month1, 10) + min(month2, 10) + min(month3, 10)) * 10

month1,month2,month3 = input().strip().split(' ')
month1,month2,month3 = [int(month1),int(month2),int(month3)]
pointsEarned = getPoints(month1, month2, month3)
print(pointsEarned)
