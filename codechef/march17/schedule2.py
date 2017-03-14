#!/bin/python3

def solve(s, n, k, ans = 0, cnt = 0):
    ans = max(ans, cnt)
    if n < 0:
        return ans
    ret = 10 ** 6
    if k > 0:
        s[n] ^= 1
        if s[n] == s[n+1]:
            ret = min(ret, solve(s, n-1, k-1, ans, cnt+1))
        else:
            ret = min(ret, solve(s, n-1, k-1, ans, 1))
        s[n] ^= 1
    if s[n] == s[n+1]:
        ret = min(ret, solve(s, n-1, k, ans, cnt+1))
    else:
        ret = min(ret, solve(s, n-1, k, ans, 1))
    return ret


for _ in range(int(input())):
    n, k = map(int, input().split())
    s = [ int(c) for c in input() ]
    s.append(-1)
    print(solve(s, n-1, k, 0))
