s = input()
k = int(input())
n = len(s)
inf = 10 ** 9 + 7
dp = [[[inf for c in range(26)] for j in range(k+2)] for i in range(n+1)]
s = [ord(c) - ord('a') for c in s]
 
def cost(a, b):
    d = b - a
    if d < 0:
        d += 26
    return d
 
for c in range(26):
    dp[1][0][c] = cost(s[0], c)
for i in range(1, n):
    w = [cost(s[i], c) for c in range(26)]
    for j in range(k+1):
        best = inf
        for c in range(26):
            new_val = dp[i][j][c] + w[c]
            if dp[i+1][j][c] > new_val:
                dp[i+1][j][c] = new_val
 
            new_val = best + w[c]
            if dp[i+1][j+1][c] > new_val:
                dp[i+1][j+1][c] = new_val
            if dp[i][j][c] < best:
                best = dp[i][j][c]
        best = inf
        for c in range(25, -1, -1):
            new_val = best + w[c]
            if dp[i+1][j+1][c] > new_val:
                dp[i+1][j+1][c] = new_val
            if dp[i][j][c] < best:
                best = dp[i][j][c]
ans = inf
for j in range(k+1):
    for c in range(26):
        if dp[n][j][c] < ans:
            ans = dp[n][j][c]
print(ans)
