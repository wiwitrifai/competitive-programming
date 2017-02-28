#!/bin/python3

import sys


y = int(input().strip())
if y < 1918:
    if y % 4 == 0:
        print('12.09.{}'.format(y))
    else:
        print('13.09.{}'.format(y))
elif y == 1918:
    print('26.09.1918')
else:
    if (y % 400 == 0) or ((y % 100 != 0) and (y % 4 == 0)):
        print('12.09.{}'.format(y))
    else:
        print('13.09.{}'.format(y))
