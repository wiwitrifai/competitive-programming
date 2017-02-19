#!/bin/python3

import sys

adj = []
p = []
def dfs(v, par):
    ret = 0
    for u in p[v]:
        ret += +1 if par == u else 0
    for u in adj[v]:
        if u != par:
            ret += dfs(u, v)
    return ret

def dfs2(v, par, cur, lim):
    if par != -1:
        for u in p[par]:
            if u == v:
                cur += 1
    for u in p[v]:
        if u == par:
            cur -= 1
    ret = cur >= lim
    for u in adj[v]:
        if u != par:
            ret += dfs2(u, v, cur, lim)
    return ret

def gcd(a, b):
    return gcd(b % a, a) if a > 0 else b

q = int(input().strip())
for a0 in range(q):
    n = int(input().strip())
    adj = [[] for _ in range(n)]
    p = [[] for _ in range(n)]
    for a1 in range(n-1):
        u,v = input().strip().split(' ')
        u,v = [int(u),int(v)]
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)
    g,k = input().strip().split(' ')
    g,k = [int(g),int(k)]
    for a1 in range(g):
        u,v = input().strip().split(' ')
        u,v = [int(u),int(v)]
        u -= 1
        v -= 1
        p[v].append(u)       
    cur = dfs(0, -1)
    ans = dfs2(0, -1, cur, k)
    d = gcd(ans, n)
    ans = ans //d
    n = n//d
    print("%d/%d" % (ans, n))