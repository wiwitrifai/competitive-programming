def gets():
    return list(map(int, raw_input().split()))
n, m, d = gets()
a = [ tuple(gets()) for i in range(n) ]
b = [ tuple(gets()) for i in range(m) ]
def mycmp(lef, rig):
    if lef[0] == rig[0]:
        return lef[1] - rig[1]
    return rig[0]-lef[0]
a.sort(cmp = mycmp)
b.sort(cmp = mycmp)
ans = 0
cur = 0
wid = 0
j = n
for i in range(n):
    cur += a[i][0]
    wid += a[i][1]
for i in range(m):
    cur += b[i][0]
    wid += b[i][1]
    while wid > d :
        j -= 1
        if j <= 0:
            break
        cur -= a[j][0]
        wid -= a[j][1]
    if j <= 0:
        break
    ans = max(ans, cur)
print ans