##
#  IEEExtreme Programming Contest 10
#  Problem : Always Be In Control 
#  Solver  : M Visat Sutarno
#  Status  : Accepted
#

from sys import stdin

A = [0, 0, 1.880, 1.023, 0.729, 0.577, 0.483, 0.419, 0.373, 0.337, 0.308]
t = int(stdin.readline().rstrip())
for _ in range(t):
    line = stdin.readline().rstrip().split()
    x, n = int(line[0]), int(line[1])
    arr = [int(l) for l in line][2:]
    avg, rng = [], []
    for i in range(0, x, n):
        grp = arr[i:i+n]
        avg.append(sum(grp)/len(grp))
        rng.append(max(grp)-min(grp))
    avg = sum(avg)/len(avg)
    rng = sum(rng)/len(rng)

    ucl = avg + A[n] * rng
    lcl = avg - A[n] * rng
    cl = avg
    sigma = (ucl-cl)/3

    control = True
    for i in range(x):
        if arr[i] > ucl or arr[i] < lcl:
            control = False
            break
        if i >= 2:
            t, b = 0, 0
            for j in range(i-2, i+1):
                if arr[j] >= cl + 2 * sigma: t += 1
                elif arr[j] <= cl - 2 * sigma: b += 1
            if t >= 2 or b >= 2:
                control = False
                break
        if i >= 4:
            t, b = 0, 0
            for j in range(i-4, i+1):
                if arr[j] >= cl + sigma:
                    t += 1
                elif arr[j] <= cl - sigma:
                    b += 1
            if t >= 4 or b >= 4:
                control = False
                break
        if i >= 7:
            t, b = 0, 0
            for j in range(i-7, i+1):
                if arr[j] >= cl: t += 1
                elif arr[j] <= cl: b += 1
            if t >= 8 or b >= 8:
                control = False
                break

    if control:
        print("In Control")
    else:
        print("Out of Control")