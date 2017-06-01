#!/bin/python3

import sys
from collections import deque

n, m = map(int, input().strip().split())
board = []
for board_i in range(n):
    board.append(input().strip())
# print(board)
q = int(input().strip())
dr = [-1, -1, 0, 1, 1, 0]
dc = [0, 1, 1, 0, -1, -1]
for a0 in range(q):
    x1,y1,x2,y2 = input().strip().split(' ')
    x1,y1,x2,y2 = [int(x1),int(y1),int(x2),int(y2)]
    dq = deque()
    ans = 0
    r = x2-x1+1
    c = y2-y1+1
    x1 -= 1
    y1 -= 1
    vis = [[0] * c for _ in range(r)]
    # print(vis)
    for i in range(r):
        for j in range(c):
            if vis[i][j] == 0:
                ans += 1
                dq.append((i, j))
                vis[i][j] = 1
                col = board[x1+i][y1+j]
                # print(x1+i, y1+j)
                # cnt = 0
                while len(dq) > 0:
                    # cnt += 1
                    x, y = dq.popleft()
                    # print(x, y)
                    for z in range(6):
                        xx, yy = x+dr[z], y+dc[z]
                        if xx < 0 or xx >= r or yy < 0 or yy >= c:
                            continue
                        # print(x1+xx, y1+yy, xx, yy, r, c)
                        # print(vis, board)
                        if vis[xx][yy] == 1 or col != board[x1+xx][y1+yy]:
                            continue
                        vis[xx][yy] = 1
                        dq.append((xx, yy))
                # print(cnt)
                # print(vis)
    print(ans)