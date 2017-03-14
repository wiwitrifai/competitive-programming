#!/bin/python3
allmask = 1 << 16
grund = [0] * allmask
recmask = []
for i in range(4):
    for j in range(4):
        for x in range(i+1, 5):
            for y in range(j+1, 5):
                now = 0
                for p in range(i, x):
                    for q in range(j, y):
                        now ^= (1 << (p * 4 + q))
                recmask.append(now)
                
for mask in range(allmask):
    st = set()
    for v in recmask:
        if v & mask == v:
            st.add(grund[mask ^ v])
    grund[mask] = 0
    ls = list(st)
    ls.sort()
    for v in ls:
        grund[mask] += grund[mask] == v

bit = [0] * (5 * 10 ** 5 + 10)
n = 0
def upd(x, v):
    global bit, n
    while x <= n:
        bit[x] ^= v
        x += x & (-x)

def get(x):
    global bit, n
    ret = 0
    while x > 0:
        ret ^= bit[x]
        x -= x & (-x)
    return ret

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = []
    for i in range(n+1):
        bit[i] = 0
    for i in range(n):
        mask = 0
        for j in range(4):
            s = input()
            for k in range(4):
                if s[k] == '1':
                    mask |= (1 << (j * 4 + k))
        input()
        a.append(grund[mask])
        upd(i+1, a[i])
        
    for __ in range(m):
        ty, *q = map(int, input().split())
        if ty == 1:
            ans = get(q[0]-1) ^ get(q[1])
            print('Pishty' if ans else 'Lotsy')
        else:
            mask = 0
            for j in range(4):
                s = input()
                for k in range(4):
                    if s[k] == '1':
                        mask |= (1 << (j * 4 + k))
            upd(q[0], grund[mask] ^ a[q[0]-1])
            a[q[0]-1] = grund[mask]