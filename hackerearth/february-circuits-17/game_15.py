#!/bin/python3

for _ in range(int(input())):
    n, q = map(int, input().split())
    obs = []
    for i in range(q):
        obs.append(tuple(map(int, input().split())))
    obs.append((n+1, 1))
    obs.append((n+1, 2))
    obs.append((n+1, 3))
    obs.sort()
    row = 2
    rup = 1
    up = set([1, 2, 3])
    st = set([1, 2, 3])
    ans = -1
    for ob in obs:
        if row != ob[0]:
            if rup == row-1:
                tmp = set()
                for i in st:
                    ok = False
                    for j in range(-1, 2):
                        if i+j in up:
                            ok = True
                    if ok:
                        tmp.add(i)
                st = tmp
                
            if len(st) == 0:
                ans = row-1
            up = st
            rup = row
            st = set([1, 2, 3])
            row = ob[0]
        st.discard(ob[1])
        if ans != -1:
            break
    if ans == -1:
        ans = n
    print(ans)
        