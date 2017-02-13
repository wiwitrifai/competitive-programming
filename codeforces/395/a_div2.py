n, m, z = map(int, input().split())
ans = 0
for i in range(n, z+1, n):
    ans += i % m == 0
print(ans)