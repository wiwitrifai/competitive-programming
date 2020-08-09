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

void solve() {
  int n;
  scanf("%d", &n);
  long long ans = 1;
  for (int i = 0; i < n; ++i)
    ans = (ans * (i+1)) % mod;
  ans = (ans - powmod(2, n-1)) % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
