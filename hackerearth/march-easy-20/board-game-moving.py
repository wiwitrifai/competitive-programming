q = int(input())
for _ in range(q):
    n = int(input())
    if n % 2 == 0 or n <= 2:
        print(0)
        continue
    k = (n + 1) // 2 - 2
    print(pow(2, k, 10 ** 9 + 7))
