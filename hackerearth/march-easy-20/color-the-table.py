mod = 10 ** 9 + 7
for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = pow(3, n+m, mod) * pow(2, n*m, mod) % mod
    print(ans)
