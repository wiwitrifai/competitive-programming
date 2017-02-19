#!/bin/python3

import sys

for line in sys.stdin:
    n, k = map(int, line.split())
    s = []
    nx = [-1] * n
    bef = [-1] * n
    for i in range(n):
        s.append(input().strip())
    g = [[False] * n for _ in range(n)]
    din = [0] * n
    dout = [0] * n
    for i in range(n):
        for j in range(n):
            if i == j: continue
            g[i][j] = s[i][1:] == s[j][:k-1]
            if g[i][j]:
                din[j] += 1
                dout[i] += 1
    for i in range(n):
        h = -1
        for j in range(n):
            if nx[j] != -1: continue
            if h == -1 or dout[h] > dout[j]:
                h = j
        if h == -1:
            continue
        to = -1
        for j in range(n):
            if bef[j] >= 0: continue
            if not g[h][j]: continue
            if to == -1 or din[to] > din[j]:
                cur = h
                while cur != -1 and cur != j:
                    cur = bef[cur]
                if cur == j:
                    continue
                to = j
        if to == -1:
            nx[h] = -2
            continue
        bef[to] = h
        nx[h] = to
        for j in range(n):
            if g[h][j]:
                din[j] -= 1
            if g[j][to]:
                dout[j] -= 1
    ans = []
    for i in range(n):
        if bef[i] >= 0: continue
        now = s[i]
        cur = nx[i]
        while cur >= 0 and cur != i:
            now += s[cur][k-1]
            cur = nx[cur]
        ans.append(now)
    if len(ans) == 0:
        assert(False)
        now = s[0]
        cur = nx[0]
        while cur >= 0 and cur != 0:
            now += s[cur][k-1]
            cur = nx[cur]
        ans.append(now)
    print(len(ans))
    print('\n'.join(ans))