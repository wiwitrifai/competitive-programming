#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

struct Fenwick {
  int bit[N];
  Fenwick() {
    memset(bit, 0, sizeof bit);
  }

  void upd(int x, int v) {
    for (++x; x < N; x += x&-x)
      bit[x] = (bit[x] + v) % mod;
  }

  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret = (ret + bit[x]) % mod;
    return ret;
  }
};

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> p(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &p[i]);
  long long ans = 1LL * k * (k - 1) / 2;
  ans %= mod;
  long long prob = powmod(k, mod - 2), q = (mod + 1 - prob) % mod;
  Fenwick sum, cnt;
  for (int i = 0; i < k; ++i) {
    sum.upd(p[i], powmod(q, mod - 1 - (k-1)));
    cnt.upd(p[i], +1);
  }
  ans = ans * powmod(2, mod - 2) % mod;
  for (int i = k; i < n; ++i) {
    long long now = powmod(q, i)* powmod(2, mod - 2) % mod;
    long long down = sum.get(p[i]), up = sum.get(N-2) - down;
    int cdown = cnt.get(p[i]), cup = cnt.get(N-2) - cdown;
    down = down * now % mod;
    up = up * now % mod;
    ans = (ans + up  + cdown - down) % mod;
    sum.upd(p[i], powmod(q, mod - 1 - i));
    cnt.upd(p[i], +1);
  }
  long long tot = 1LL * n * (n - 1) / 2;
  tot %= mod;
  ans = (tot - ans) % mod;
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
