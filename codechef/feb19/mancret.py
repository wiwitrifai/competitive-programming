#!/bin/env python3
from sys import stdout

def ask(x, y):
    print('Q {} {}'.format(x, y))
    stdout.flush()
    d = int(input())
    assert(d >= 0)
    return d

def answer(xl, yl, xu, yu):
    print('A {} {} {} {}'.format(xl, yl, xu, yu))
    stdout.flush()
    d = int(input())
    assert(d == 1)

t = int(input())
for _ in range(t):
    inf = 10 ** 9
    AB = ask(0, 0)
    AC = ask(inf, 0)
    CD = ask(inf, inf)
    BD = ask(0, inf)
    diff = BD - CD
    A = ask((diff + inf) // 2, 0)
    B = AB - A
    C = AC - A
    D = BD - B
    answer(B, A, inf-C, inf-D)