for _ in range(int(input())):
    l, r, s = map(int, input().split())
    lo = (l + s - 1) // s
    hi = r // s
    if lo > hi:
        lo, hi = -1, -1
    print(lo, hi)
