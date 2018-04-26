#include <bits/stdc++.h>

using namespace std;


const int N = 6e6 + 6, mod = 1e9 + 7;
long long fac[N], inv[N];
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = b * r % mod;
  return r;
}

int a[N];
bool cek[2][N];

long long C(int n, int k) {
  return n < k || k < 0 ? 0 : (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

long long cat(int n) {
  return C(2 * n, n) * powmod(n+1, mod-2) % mod;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = (fac[i-1] * i) % mod;
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-1; i > 0; --i)
    inv[i-1] = inv[i] * i % mod;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 0) {
      printf("%lld\n", cat(n));
      continue;
    }
    long long ans = 0;
    int le = N, ri = 0;
    int now = 1;
    for (int i = 0; i < k; ++i) {
      scanf("%d", a+i);
      now &= a[i] > ri || a[i] < le;
      cek[0][i] = now;
      le = min(a[i], le);
      ri = max(a[i], ri);
    }
    le = N, ri = 0;
    now = 1;
    for (int i = k-1; i >= 0; --i) {
      now &= a[i] > ri || a[i] < le;
      cek[1][i] = now;
      le = min(a[i], le);
      ri = max(a[i], ri);
    }
    for (int i = 0; i < k; ++i) {
      if (i > 0 && i+1 < k && 1LL * (a[i+1] - a[i]) * (a[i-1] - a[i]) >= 0)  continue;
      if (!cek[0][i] || !cek[1][i]) continue;
      ++ans;
    }
    sort(a, a+k);
    for (int i = 1; i < k; ++i) {
      ans = ans * cat(a[i]-a[i-1]-1) % mod;
    }
    ans = ans * cat(n-a[k-1] + a[0]) % mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}