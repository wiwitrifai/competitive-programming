n = int(input().strip())
ans = n % 10
n //= 10
ans += n % 10
n //= 10
ans += n
print(ans)
