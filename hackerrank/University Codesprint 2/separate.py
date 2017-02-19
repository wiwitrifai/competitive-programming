#!/bin/python3

import sys


q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    n = len(s)
    ans = -1
    for i in range(1, n, 1):
        a = int(s[:i])
        ans = a
        a += 1
        ok = 1
        cur = 0
        for j in range(i, n, 1):
            if cur == 0 and s[j] == '0':
                ok = 0
                break
            cur = cur * 10 + int(s[j])
            if (cur > a):
                ok = 0
                break
            elif cur == a:
                a += 1
                cur = 0
        if cur != 0:
            ok = 0
        if ok == 0:
            ans = -1
        else:
            break
    if ans == -1:
        print('NO')
    else:
        print('YES', ans)