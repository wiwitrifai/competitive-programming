#!/bin/python3

def intersec(a, b, x, y):
    return a <= y and x <= b

n, m = map(int, input().strip().split())
a = []
for i in range(n):
    tmp = list(map(int, input().strip().split()))
    cnt = len(tmp)
    for j in range(cnt):
        a.append((tmp[j] + (j & 1), (j & 1) ^ 1, i))
a.sort()
st = set()
seg = []
cur = 0
for it in a:
    if it[0] == cur:
        if it[1]:
            st.add(it[2])
        else:
            st.discard(it[2])
    else:
        if len(st) > 1:
            seg.append((cur, -2))
        elif len(st) == 1:
            for e in st:
                seg.append((cur, e))
        else:
            seg.append((cur, -1))
        cur = it[0]
        if it[1]:
            st.add(it[2])
        else:
            st.discard(it[2])
if len(st) > 1:
    seg.append((cur, -2))
elif len(st) == 1:
    for e in st:
        seg.append((cur, e))
else:
    seg.append((cur, -1))

nseg = len(seg)
ans = [0] * n
for _ in range(m):
    b = list(map(int, input().strip().split()))
    idd = -1
    ln = len(b)
    ok = True
    for i in range(0, ln, 2):
        assert(b[i] >= 0)
        l = 0
        r = nseg-1
        while l < r:
            mid = (l + r+1)//2
            if seg[mid][0] <= b[i]:
                l = mid
            else:
                r = mid-1
        assert(seg[l][0] <= b[i])
        while l < nseg and seg[l][0] <= b[i+1]:
            if seg[l][1] == -2:
                ok = False
                break
            elif seg[l][1] != -1:
                if idd != -1 and idd != seg[l][1]:
                    ok = False
                    break
                idd = seg[l][1]
            l += 1
        if not ok:
            break
    if ok and idd != -1:
        ans[idd] += 1
print('\n'.join(map(str, ans)))
