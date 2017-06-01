#!/bin/python3

def cross(x1, y1, x2, y2, x3, y3):
    x1 -= x2
    x3 -= x2
    y1 -= y2
    y3 -= y2
    return x1 * y3 - x3 * y1

def main():
    w, h = map(int, input().strip().split())
    xc, yc, r = map(int, input().strip().split())
    x1, y1, x3, y3 = map(int, input().strip().split())

    px = [[False] * w for i in range(h)]

    if x3 < x1:
        x1, y1, x3, y3 = 2*x3, 2*y3, 2*x1, 2*y1
    dx = y3 - y1
    dy = x1 - x3
    x2 = 0
    y2 = 0
    while abs(x2-x3) != abs(x2+dx-x1): x2 += 1
    while abs(y2-y1) != abs(y2+dy-y3): y2 += 1
    x4 = x2 + dx
    y4 = y2 + dy

    for i in range(w):
        for j in range(h):
            dx = xc - i
            dy = yc - j
            if dx * dx + dy * dy <= r * r:
                px[j][i] = True
                continue
            ok = True
            col = -1
            crs = cross(x1, y1, x2, y2, 2*i, 2*j)
            if crs != 0:
                if col == -1:
                    col = crs > 0
                elif col != (crs > 0):
                    ok = False
            crs = cross(x2, y2, x3, y3, 2*i, 2*j)
            if crs != 0:
                if col == -1:
                    col = crs > 0
                elif col != (crs > 0):
                    ok = False
            crs = cross(x3, y3, x4, y4, 2*i, 2*j)
            if crs != 0:
                if col == -1:
                    col = crs > 0
                elif col != (crs > 0):
                    ok = False
            crs = cross(x4, y4, x1, y1, 2*i, 2*j)
            if crs != 0:
                if col == -1:
                    col = crs > 0
                elif col != (crs > 0):
                    ok = False
            if ok:
                px[j][i] = True
    for i in range(h):
        for j in range(w):
            print('%s' % ('#' if px[i][j] else '.'), end='')
        print() 

if __name__ == "__main__":
    main()