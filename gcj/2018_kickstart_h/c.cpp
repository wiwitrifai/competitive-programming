#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

void solve(int tc) {
  long long ans = 0;
  int n, m;
  scanf("%d %d", &n, &m);
  long long pw = 1;
  for (int i = 0; i <= m; ++i) {
    long long cnt = C(m, i) * fac[2 * n - i] % mod;
    cnt = cnt * pw % mod;
    if (i & 1)
      cnt = mod - cnt;
    ans = (ans + cnt) % mod;
    pw = pw * 2 % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("Case #%d: %lld\n", tc, ans);
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}