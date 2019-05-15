#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, mod = 1e9 + 7;

struct BIT {
  int bit[N];
  BIT() {
    memset(bit, 0, sizeof bit);
  }
  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret = (ret + bit[x]) % mod;
    return ret;
  }
  void upd(int x, int v) {
    v %= mod;
    if (v < 0) v += mod;
    for (++x; x < N; x += x&-x)
      bit[x] = (bit[x] + v) % mod;
  }
  void reset() {
    memset(bit, 0, sizeof bit);
  }
} cnt;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    v[i] = a[i];
  }
  sort(v.begin(), v.end());
  auto pos = [&v] (int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int p = pos(a[i]);
    cnt.upd(p, i+1);
    long long sum = cnt.get(p);
    sum = (sum * (n - i)) % mod;
    ans = (ans + 1LL * sum * a[i]) % mod;
  }
  cnt.reset();
  for (int i = n-1; i >= 0; --i) {
    int p = pos(a[i]);
    long long sum = cnt.get(p);
    cnt.upd(p, n-i);
    sum = (sum * (i+1)) % mod;
    ans = (ans + 1LL * sum * a[i]) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
