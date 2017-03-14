#!/bin/python3

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    if n <= 1000:
        ans = 0
        for s in range(n):
            dp = [0]
            for t in range(s+1, n):
                now = dp[t-s-1] + a[t-1]
                if t-s >= 2:
                    now = min(now, dp[t-s-2] + b[t-2])
                if t-s >= 3:
                    now = min(now, dp[t-s-3] + c[t-3])
                dp.append(now)
                ans += now
        print(ans)
    else:
        ans = 0
        for i in range(n-1):
            ans += a[i] * (i+1) * (n-1-i)
        print(ans)