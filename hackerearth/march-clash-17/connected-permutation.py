x = pow(5, 441, 924844033)
print(x)
print(pow(x, 924844033-2, 924844033))
print(pow(x, 1<<21, 924844033))
n = int(input())
fac = [1] * (n + 1)
mod = 924844033
fac[0] = 1
for i in range(1, n+1):
    fac[i] = (fac[i-1] * i) % mod
dp = [1] * (n + 1)
for i in range(2, n+1):
    dp[i] = 0
    for j in range(1, i):
        dp[i] = (dp[i] + j * dp[j] * fac[i-j-1]) %  mod
for i in range(1, n+1):
    print(dp[i])