n = int(input())
p = list(map(int, input().split()))

used = set()
ans = []
done = False
for i in range(n):
    x = p[i]
    l = min(x, n-1)
    while l >= 0 and l in used:
        l -= 1
    if l < 0:
        for y in range(n):
            if y not in used:
                ans.append(y)
        break
    if l < x:
        ans.append(l)
        used.add(l)
        for y in range(n-1, -1, -1):
            if y not in used:
                ans.append(y)
        done = True
        break
    else:
        ans.append(l)
        used.add(l)

if not done:
    pos = n-2
    while pos >= 0 and ans[pos] < ans[pos+1]:
        pos -= 1
    if pos < 0:
        ans = [-1]
    else:
        oth = pos+1
        while oth + 1 < n and ans[oth+1] < ans[pos]:
            oth += 1
        ans[pos], ans[oth] = ans[oth], ans[pos]
        ans = ans[:pos+1] + sorted(ans[pos+1:])[::-1]
print(" ".join(map(str, ans)))
