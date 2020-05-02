#!/bin/python3

n, m = map(int, input().strip().split())
edge = []
for i in range(m):
    edge.append(tuple(map(lambda x : int(x)-1, input().strip().split())))
ad = [[] for i in range(n)]
for i in range(m):
    e = edge[i]
    ad[e[0]].append(i)
    ad[e[1]].append(i)
p = [0] * n
ans = [0] * m
deg = [len(ad[i]) for i in range(n)]
ready = set()
nor = set()
woke = [False] * n
for i in range(n):  
    if deg[i] <= 1:
        ready.add(i)
        woke[i] = True
    else:
        nor.add(i)
cur = 0
cnt = m
def dfs(v, ok):
    global cur, cnt
    while True:
        if p[v] >= len(ad[v]):
            return
        while p[v] < len(ad[v]):
            e = ad[v][p[v]]
            p[v] += 1
            if ans[e] == 0:
                a, b = edge[e]
                deg[a] -= 1
                deg[b] -= 1
                cur += 1
                ans[e] = cur
                cnt -= 1
                if ok:
                    nor.discard(v)
                    ready.add(v)
                    woke[v] = True
                v = a+b-v
                ok = True
                break
while cnt > 0:
    v = -1
    if len(ready) > 0:
        v = ready.pop()
    elif len(nor) > 0:
        v = nor.pop()
    dfs(v, False)
    if p[v] < len(ad[v]):
        if woke[v]:
            ready.add(v)
        else:
            nor.add(v)

def gcd(a, b):
    return b if a == 0 else gcd(b % a, a)
for i in range(n):
    if len(ad[i]) > 1:
        g = 0
        for e in ad[i]:
            g = gcd(g, ans[e])
        # assert(g == 1)
assert(cnt <= 0)
print(cur)
print('\n'.join(map(str, ans)))