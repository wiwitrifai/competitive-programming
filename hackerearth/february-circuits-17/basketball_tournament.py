#!/bin/python3

n, k = map(int, input().strip().split())
a, b = map(int, input().strip().split())
city = [tuple(map(int, input().strip().split())) for i in range(n)]
living = [a * c[2] ** 0.5 for c in city]
flight = [[0 if i == j else b * (((city[i][0]-city[j][0]) ** 2 + (city[i][1]-city[j][1]) ** 2) / (city[i][2] * city[j][2])) ** 0.5 for i in range(n)] for j in range(n)]
m = 4 * n
schedule = [[(-1, -1) for i in range(m)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        for z in range(m):
            if schedule[i][z] == (-1, -1) and schedule[j][z] == (-1, -1):
                schedule[i][z] = (j, i)
                schedule[j][z] = (i, i)
                break
pos = [i for i in range(n)]
events = []
last = 1
cnt = 0
for d in range(m):
    # arrival
    for i in range(n):
        if pos[i] != schedule[i][d][1] and schedule[i][d][1] != -1:
            pos[i] = schedule[i][d][1]
            last = d * k + 1
            events.append((last, 1, i+1, pos[i]+1))

    # match
    for i in range(n):
        if schedule[i][d][1] == i:
            cnt += 1
            b = schedule[i][d][0]
            last = d * k + 1
            events.append((last, 2, i+1, b+1))
            assert(pos[b] == i and pos[i] == i)

    # live
    for i in range(n):
        cur = pos[i]
        now = d+1
        while now < m and schedule[i][now][0] == -1: now += 1
        if now == m or now * k == d * k + 1:
            continue
        nxt = schedule[i][d+1][now]
        now = (now - d) * k-1
        best = living[cur] * k + flight[cur][nxt] 
        select = cur
        for j in range(n):
            score = living[j] * now + flight[j][nxt] + flight[cur][j]
            if score < best:
                best = score
                select = j
        if cur != select:
            last = d * k + 2
            events.append((last, 1, i+1, select+1))
            pos[i] = select
assert(cnt == n * (n-1))
print(last, len(events))
for e in events:
    print(' '.join(map(str, e)))
