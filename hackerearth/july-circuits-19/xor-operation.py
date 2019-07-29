def main():
    for _ in range(int(input())):
        n, k, s = map(int, input().split())
        mod = 10 ** 9 + 7
        ans = 0
        for p in range(30):
            cur = n >> p
            one = cur // 2
            zero = cur - one
            zero <<= p
            one <<= p
            if cur & 1:
                one += n - (cur << p) + 1
            else:
                zero += n - (cur << p) + 1
            assert(one + zero == n+1)
            cur = [0, 0]
            cur[(s >> p) & 1] = 1
            denom = pow(n+1, mod-2, mod)
            prob = [ zero * denom % mod, one * denom % mod ]
            def combine(a, b):
                res = [0, 0]
                for i in range(2):
                    for j in range(2):
                        res[i^j] = (res[i^j] + a[i] * b[j]) % mod
                return res;
            for i in range(30):
                if (k >> i) & 1:
                    cur = combine(cur, prob)
                prob = combine(prob, prob)
            ans = (ans + (cur[1] << p)) % mod

        print(ans)

if __name__ == "__main__":
    main()
