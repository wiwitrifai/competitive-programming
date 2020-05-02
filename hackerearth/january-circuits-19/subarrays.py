n = int(input())
a = list(map(int, input().split()))
c = 0
ans = 0
for x in a:
    if c < 0:
        c = 0
    c += x
    if c > ans:
        ans = c
k = 0
c = 0
for x in a:
    if c < 0:
        c = 0
    c += x
    if c == ans:
        c = 0
        k += 1
print(ans, k)