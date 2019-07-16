n, m, g = map(int, input().strip().split())
t = list(map(int, input().strip().split()))
a = list(map(int, input().strip().split()))
maks = 0
for i in range(1, n):
    maks = max(maks, t[i]-t[i-1])
ans = sum(x <= maks for x in a)
print(ans)
