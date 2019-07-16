t = int(input())
for _ in range(t):
    n = int(input())
    last = [0 for i in range(26)]
    for i in range(n):
        s = input()
        for c in s:
            idx = ord(c) - ord('a')
            if last[idx] == i:
                last[idx] += 1
    ans = sum(map(lambda x : x == n, last))
    print(ans)