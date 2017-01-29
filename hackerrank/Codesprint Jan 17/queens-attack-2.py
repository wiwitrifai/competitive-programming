#!/bin/python3

import sys


n,k = input().strip().split(' ')
n,k = [int(n),int(k)]
rQueen,cQueen = input().strip().split(' ')
rQueen,cQueen = [int(rQueen),int(cQueen)]
obs = set()
for a0 in range(k):
    rObstacle,cObstacle = input().strip().split(' ')
    rObstacle,cObstacle = [int(rObstacle),int(cObstacle)]
    obs.add((rObstacle, cObstacle))
ans = 0
for dx in range(-1, 2, 1):
    for dy in range (-1, 2, 1):
        if dx == 0 and dy == 0:
            continue
        x = rQueen + dx
        y = cQueen + dy
        while x <= n and x > 0 and y <= n and y > 0:
            if (x, y) in obs:
                break
            ans += 1
            x += dx
            y += dy
print(ans)