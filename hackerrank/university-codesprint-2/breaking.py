n = int(input())
a = list(map(int, input().split()))
ma, mi = a[0], a[0]
ans1, ans2 = 0, 0
for v in a:
    if v > ma:
        ans1 += 1
        ma = v
    if v < mi:
        ans2 += 1
        mi = v
print(ans1, ans2)