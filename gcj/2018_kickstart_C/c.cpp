#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long geom(long long p, long long n) {
  if (p == 1) return n;
  long long ret = (powmod(p, n) - 1) * powmod(p-1, mod-2) % mod;
  ret = ret * p % mod;
  if (ret < 0) ret += mod;
  return ret;
}

const int N = 1e6 + 6;

long long sum[N];
int a[N];

void solve() {
  int n, k, xx, yy, c, d, e1, e2, f;
  scanf("%d %d %d %d %d %d %d %d %d", &n, &k, &xx, &yy, &c, &d, &e1, &e2, &f);
  for (int i = 0; i < n; ++i) {
    a[i] = (xx + yy) % f;
    if (a[i] < 0) a[i] += f;
    int xn = (1LL * c * xx + 1LL * d * yy + e1) % f;
    int yn = (1LL * d * xx + 1LL * c * yy + e2) % f;
    xx = xn, yy = yn;
  }
  sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    sum[i] = (sum[i-1] + geom(i, k)) % mod;
  }
  long long ans = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    cur = (cur + 1LL * sum[i+1] * a[i]) % mod;
    ans = (ans + cur) % mod;
  }
  printf("%lld\n", ans);
}


int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}