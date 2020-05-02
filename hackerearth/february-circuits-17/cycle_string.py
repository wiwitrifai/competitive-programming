#!/bin/python3
 
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
 
ans = 10 ** 9
for a0 in range(2):
    for a1 in range(2):
        c = [x for x in a]
        cnt = 0
        if a0:
            c[n-2] ^= 1
            c[n-1] ^= 1
            c[0] ^= 1
            cnt += 1
        if a1:
            c[n-1] ^= 1
            c[0] ^= 1
            c[1] ^= 1
            cnt += 1
        for i in range(n):
            if c[i] != b[i]:
                for j in range(3):
                    c[(i+j) % n] ^= 1
                cnt += 1
        if c[0] == b[0] and c[1] == b[1] and cnt < ans:
            ans = cnt
if ans > n:
    ans = 'Impossible'
print(ans)
              