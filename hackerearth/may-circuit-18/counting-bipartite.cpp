#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353;
long long powmod(long long b, long long p) {
    long long r = 1;
    for (; p; p >>= 1, b = b * b % mod)
        if (p & 1)
            r = r * b % mod;
    return r;
}
 
const int N = 1e6 + 6;
 
long long fac[N], inv[N];
long long C(int n, int k) {
    return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}
 
int main() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = powmod(fac[i], mod-2);
    }
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        long long cur = powmod(2, i)-1;
        if (cur < 0) cur += mod;
        cur = powmod(cur, m);
        if ((n-i) & 1)
            cur = mod - cur;
        ans = (ans + cur * C(n, i)) % mod;
    }
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
    return 0;
}