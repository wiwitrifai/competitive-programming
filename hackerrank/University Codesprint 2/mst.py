#!/bin/python3

import sys


g = int(input().strip())
for a0 in range(g):
    n,m,s = input().strip().split(' ')
    n,m,s = [int(n),int(m),int(s)]
    if (m <= (n) * (n-1) // 2 - (n-2)):
        print(s-(n-1)+m)
    else:
        n -= 2
        k = m - (n+1) * (n) // 2
        s -= n
        ans = (n+1) *(n)//2 + k * s
        le = 1
        if n * (n+1)//2 <= k * n and s >= n:
            z = (s-le)//(n+1)
            while (le + z <= s - z * n): z += 1
            while (le + z > s - z * n and z > 0): z -= 1
            ans += z * (n * (n+1)//2 - k*n)
            s -= z * n
            le += z;
        z = s-le-1
        if (z * ((n) * 2-(z-1)) < 2 * z * k and z <= n and le+1 <= s-z and z > 0):
            ans += (z * ((n) * 2-(z-1)) - 2 * z * k) // 2
            le += 1
            s -= z
        print(ans)
