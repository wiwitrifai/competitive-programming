#include <bits/stdc++.h>

using namespace std;

const int K = 60, mod = 1e9 + 7;

void solve() {
  int n;
  scanf("%d", &n);
  vector<long long> x(n);
  vector<long long> s(K, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &x[i]);
    for (int j = 0; j < K; ++j) {
      s[j] += (x[i] & (1LL << j)) % mod;
    }
  }
  for (int i = 0; i < K; ++i)
    s[i] %= mod;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long sand = 0, sor = 0;
    for (int j = 0; j < K; ++j) {
      long long cur = 1LL << j;
      if (x[i] & cur) {
        sand += s[j];
        cur %= mod;
        sor += cur * n % mod;
      } else {
        sor += s[j];
      }
      sor %= mod;
      sand %= mod;
    }
    ans = (ans + sor * sand) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
