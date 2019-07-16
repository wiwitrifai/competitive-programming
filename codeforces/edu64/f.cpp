#include <bits/stdc++.h>

using namespace std;

const int N = 5050, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int cnt[N];
long long inv[N];
long long dp[N][N];

void add(long long & var, long long val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> cards;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    cards.push_back(a);
  }
  vector<int> uniq = cards;
  sort(uniq.begin(), uniq.end());
  uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
  for (int & x : cards) {
    x = lower_bound(uniq.begin(), uniq.end(), x) - uniq.begin();
    ++cnt[x];
  }
  for (int i = 1; i <= n; ++i)
    inv[i] = powmod(i, mod-2);
  dp[0][0] = 1;
  long long ans = 0;
  for (int i = 0; i < (int)uniq.size(); ++i) {
    for (int j = 0; j <= i; ++j) {
     long long p = 1LL * cnt[i] * inv[n-j] % mod;
     add(dp[i+1][j+1], 1LL * dp[i][j] * p % mod);
    }
    for (int j = 1; j <= i+1; ++j) {
      if (n-j <= 0) continue;
      long long p = 1LL * (cnt[i]-1) * inv[n-j] % mod;
      add(ans, 1LL * dp[i+1][j] * p % mod); 
    }
    for (int j = 0; j <= i; ++j)
      add(dp[i+1][j], dp[i][j]);
  }
  printf("%lld\n", ans);
  return 0;
}
