def solve(n, m, a):
    if n == 0:
        return 0, 1
    if n == 1:
        return a[0], 1
    d = (a[1]-a[0]) % m
    if d < 0: d += m
    st = set(a)
    cnt = 0
    for v in a:
        cnt += ((v + d) % m) in st
    cnt = n-cnt
    d = (d * pow(cnt, m-2, m)) % m
    now = a[0]
    while (now + m - d) % m in st:
        now = (now + m - d) % m
    for i in range(n):
        if (now + i*d) % m not in st:
            return -1, -1
    return now, d


m, n = map(int, input().split())
a = list(map(int, input().split()))
if n * 2 > m:
    st = set(a)
    b = [i for i in range(m) if i not in st]
    f, d = solve(len(b), m, b)
    f = (f + d * (m-n)) % m
else:
    f, d = solve(n, m, a)
if f < 0 or d < 0:
    print(-1)
else:
    print(f, d)