
mod = 10**9+7
def read():
    return [int(x) for x in input().strip().split()]
 
n = int(input().strip())
a = read()
b = read()
a.sort()
b.sort()
ans = sum(abs(x-y) % mod for x, y in zip(a, b))
print(ans % mod)
