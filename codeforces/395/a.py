n = int(input())
g = [[] for _ in range(n)]
for _ in range(n-1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)
c = list(map(int, input().split()))
dif = [0 for _ in range(n)]
cnt = 0
for v in range(n):
    dif[v] = 0
    for u in g[v]:
        if c[u] != c[v]:
            dif[v] += 1
    cnt += dif[v] > 0
ans = -1
for v in range(n):
    if dif[v] + 1 >= cnt:
        ans = v+1
if ans >= 0:
    print('YES\n%d' % ans)
else:
    print('NO')