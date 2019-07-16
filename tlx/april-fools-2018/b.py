n = int(input())
l = [int(input()) for i in range(n)]
ans = abs(l[0] - l[1])
for i in range(n):
    for j in range(i+1, n):
        ans = min(ans, abs(l[j] - l[i]))
def fac(n):
    if n == 0:
        return 1;
    return n * fac(n-1)
print(fac(ans))