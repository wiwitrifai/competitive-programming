for _ in range(int(input())):
    n = int(input()) + 1
    p = 2
    ans = False
    while p * p <= n:
        if n % p == 0:
            ans = True
        p += 1
    if n == 2:
        ans = True
    print("YES" if ans else "NO")
