n, m = map(int, input().split())
edge = []
deg = [n-1] * (n + 1)
for _ in range(m):
    u, v = map(int, input().split())
    deg[u] -= 1
    deg[v] -= 1
    edge.append((u, v))
dif = 0
for u, v in edge:
    dif += deg[u]
    dif += deg[v]
assert((dif & 1) == 0)
dif = dif // 2
ans = n * (n - 1) * (n - 2) // 6 - dif
print(ans)
