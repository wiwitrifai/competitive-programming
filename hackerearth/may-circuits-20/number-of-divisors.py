def calc(n):
    return n * (n + 1) // 2

for _ in range(int(input())):
    n, k = map(int, input().split())
    ans = calc(n)
    n //= k
    while n > 0:
        ans -= calc(n) * (k-1)
        n //= k
    print(ans)
