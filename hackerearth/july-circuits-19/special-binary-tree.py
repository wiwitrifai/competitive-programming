def main():
    N = 2 * 10 ** 6
    mod = 10 ** 9 + 7
    def fact_generator(n):
        cur = 1
        for i in range(n+1):
            if i:
                cur = cur * i % mod
            yield cur
    fact = list(fact_generator(N))
    def inv_generator(n):
        cur = pow(fact[n], mod-2, mod)
        for i in range(n, -1, -1):
            yield cur
            cur = cur * i % mod
    inv = list(inv_generator(N))[::-1]
    def comb(n, k):
        if n < k or k < 0:
            return 0
        return (inv[n-k] * inv[k] % mod) * fact[n] % mod;

    for _ in range(int(input())):
        n = int(input())
        full = 1
        while full * 2 + 1 <= n:
            full = full * 2 + 1
        even = n // 2
        odd = n - even
        mid = (full + 1) // 2
        ans = (comb(mid, even-mid+1) * comb(mid, odd-mid) + \
                comb(mid, even-mid) * comb(mid, odd-mid+1)) % mod
        ans = (ans * fact[even] % mod) * fact[odd] % mod
        print(ans)

if __name__ == "__main__":
    main()
