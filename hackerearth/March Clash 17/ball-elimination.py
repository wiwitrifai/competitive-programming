n = int(input())
a = list(map(int, input().split()))
dp = [[-1 for i in range(n)] for j in range(n)]
for i in range(n):
    dp[i][i] = 1
for i in range(n-1):
    dp[i][i+1] = 0 if a[i] == a[i+1] else 2
for l in range(2, n):
    for i in range(n-l):
        dp[i][i+l] = dp[i+1][i+l-1] if a[i] == a[i+l]  else n
        dp[i][i+l] = min(dp[i+1][i+l] + 1, dp[i][i+l-1] + 1, dp[i][i+l])
        for j in range(i+1, i+l):
            if a[i] == a[j]:
                cur = (dp[i+1][j-1] if i+1 <= j-1 else 0) + dp[j+1][i+l]
                dp[i][i+l] = min(dp[i][i+l], cur)
print(dp[0][n-1])