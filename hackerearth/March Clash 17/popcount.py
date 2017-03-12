#!/bin/python3
s = input()
n = len(s)
d = [int(s[x]) for x in range(n-1, -1, -1)]
ans = 0
i = 0
while i < n:
    if (d[i] == 0):
        i += 1
        continue
    ans += 1
    if i + 1 < n and d[i] == d[i+1]: 
        j = i
        while j < n:
            d[j] ^= 1
            if d[j] == 1:
                break
            j += 1
        if j == n:
            d.append(1)
            n += 1
    i += 1
print(ans)
