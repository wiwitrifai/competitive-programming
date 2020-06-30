b, w = map(int, input().strip().split())
ans = 0
if b > w:
    b, w = w, b
while True:
    s = ans + 1
    s *= s
    x = s // 2
    y = s - x
    if x > b or y > w:
        break
    ans += 1

print(ans)
