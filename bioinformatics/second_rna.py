from collections import deque
rna = input()
dq = deque()
comp = {'A' : 'U', 'U' : 'A', 'C' : 'G', 'G' : 'C'}
for c in rna:
    if len(dq) == 0:
        dq.appendleft(c)
        continue
    if dq[0] == comp[c]:
        dq.popleft()
        continue
    dq.appendleft(c)
n = len(dq)
if n == 0:
    print('perfect')
else:
    i = 0
    j = n-1
    while i < j:
        if dq[i] != comp[dq[j]]:
            break
        i += 1
        j -= 1
    ok = False
    a = i+1
    b = j
    while a < b:
        if dq[a] != comp[dq[b]]:
            break
        a += 1
        b -= 1
    if a > b:
        ok = True
    a = i
    b = j-1
    while a < b:
        if dq[a] != comp[dq[b]]:
            break
        a += 1
        b -= 1
    if a > b:
        ok = True
    if ok:
        print("almost perfect")
    else:
        print('imperfect')