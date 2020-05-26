x, n = map(int, input().split())
p = 1
if n >= 5:
    p = 0
else:
    for i in range(1, n+1):
        p = p * i % 10

x %= 10
ans = 1
for i in range(p):
    ans = ans * x % 10
print(ans)
