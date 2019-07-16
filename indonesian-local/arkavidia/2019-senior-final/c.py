#!/bin/env python3
from fractions import Fraction
for _ in range(int(input())):
  d, x, y, k, a = map(int, input().strip().split())
  if a > k:
    print("YA")
    continue
  A = a * a - k * k
  B = 2 * k * x
  C = - (x * x + (y + d) * (y + d))
  if A > 0:
    print('YA')
    continue
  if A == 0:
    print("YA" if B > 0 else "TIDAK")
    continue
  t = - Fraction(B // 2, A)
  res = t * t * A + t * B + C
  if res > 0:
    assert(t * a > y+d and t * k > x)
  print("YA" if res > 0 else "TIDAK")