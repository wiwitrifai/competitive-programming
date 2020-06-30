#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e18;
const int mod = 998244353;

long long mul(long long x, long long y) {
  if (x == 0) return 0;
  if (inf / x < y) return inf;
  return min(x * y, inf);
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

void solve() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  vector<long long> pm(1, 1);
  while (mul(pm.back(), m) <= n) {
    pm.push_back(pm.back() * m);
  }
  int s = pm.size();
  vector<long long> cnt(s, 0);
  for (int i = 0; i < s; ++i) {
    long long cur = pm[i];
    cnt[i] = n / cur;
    cnt[i] -= cnt[i] / m;
  }
  long long ans = 0, ways = 1;
  for (int i = 0; i+1 < s; ++i)
    cnt[i] -= cnt[i+1];
  for (int i = 0; i < s; ++i) {
    if (cnt[i] == 0) continue;
    int len = i+1;
    ans += cnt[i] * ((len + 1) / 2);
    if ((len & 1) == 0) {
      ways = ways * powmod(len/2 + 1, cnt[i]) % mod;
    }
  }
  printf("%lld %lld\n", ans, ways);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
