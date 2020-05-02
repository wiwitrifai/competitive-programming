class BIT:
    def __init__(self, N):
        self.N = N
        self.b = [0] * (N+1)
    
    def update(self, x, v):
        while x < self.N:
            self.b[x] += v
            x += x&-x
    
    def get(self, x):
        ret = 0
        while x > 0:
            ret += self.b[x]
            x -= x&-x
        return ret
 
def read_seq():
    return list(map(int, input().strip().split()))
    
mod = 10 ** 9 + 7
 
def inv(x):
    return pow(x, mod-2, mod)
 
def fac(x):
    ret = 1
    for i in range(1, x+1):
        ret = ret * i % mod
    return ret
 
if __name__ == "__main__":
    n = int(input().strip())
    a = read_seq()
    b = read_seq()
    ans = 0
    N = 2 * 10 ** 5
    cnt = [0]  * (N + 1)
    for x in a:
        cnt[x] += 1
    bit = BIT(N)
    mul = fac(n)
    for i in range(N+1):
        if cnt[i] > 0:
            bit.update(i, cnt[i])
            mul = mul * inv(fac(cnt[i])) % mod
    for i in range(n):
        x = b[i]
        mul = mul * inv(n-i) % mod
        ans = (ans + mul * bit.get(x-1)) % mod
        if cnt[x] == 0:
            break
        mul = mul * cnt[x] % mod
        cnt[x] -= 1
        bit.update(x, -1)
    print(ans)
