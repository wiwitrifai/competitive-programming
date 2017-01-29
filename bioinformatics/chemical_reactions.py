import sys
from collections import deque
ans = set(map(int, input().split()))
rea = dict()
to = [[] for _ in range(10 ** 5 + 6)]
need = list()
cntr = 0
for line in sys.stdin:
    line = (line.split('\n'))[0]
    react = line.split('->')
    frm = set(map(int, react[0].split('+')))
    res = list(map(int, react[1].split('+')))
    for x in frm:
        to[x].append(cntr)
    need.append(frm)
    rea[cntr] = res
    cntr += 1
que = deque()
for x in ans:
    for y in to[x]:
        need[y].remove(x)
        if len(need[y]) == 0:
            que.append(y)
while len(que) != 0:
    now = que[0]
    que.popleft()
    for res in rea[now]:
        if res in ans:
            continue
        ans.add(res)
        for r in to[res]:
            need[r].remove(res)
            if len(need[r]) == 0:
                que.append(r)
print(' '.join(map(str, ans)))