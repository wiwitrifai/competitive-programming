#/bin/python3

def gets():
    return list(map(int, input().strip().split()))
n = int(input())
s = gets()
bit = [[0] + [1 if (s[j] & (1<<i)) else 0 for j in range(n)] for i in range(20)]
for i in range(20):
    for j in range(n):
        bit[i][j+1] += bit[i][j]
q = int(input())
for _ in range(q):
    xl, yl, xr, yr = gets()
    ans = 0
    for j in range(20):
        onex, oney = bit[j][xr] - bit[j][xl-1], bit[j][yr] - bit[j][yl-1]
        zerox, zeroy = xr-xl+1-onex, yr-yl+1-oney
        ans += (onex * zeroy + oney * zerox) << j
    print(ans)
