#include <bits/stdc++.h>

using namespace std;

const int N = 5050, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int dp[N], dp2[N][2], cnt[N], ujung[N];

int a, b;

void upd(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  memset(dp, 0, sizeof dp);
  int n;
  scanf("%d %d %d", &n, &a, &b);
  if (a > b)
    swap(a, b);
  dp[0] = 2;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j <= n && j - i < b; ++j) {
      upd(dp[j], dp[i]);
    }
  }
  long long ans = (powmod(2, n) - dp[n]) % mod;
  if (a < b) {
    for (int i = 1; i < b; ++i) {
      upd(cnt[i], 1);
    }
    for (int i = 1; i < b; ++i) {
      for (int j = i+a+1; j < b; ++j) {
        int add = j - i;
        upd(cnt[j], 1LL * (add - a) * cnt[i] % mod);
      }
    }
    for (int i = a+1; i < b; ++i) {
      for (int j = a; j < i; ++j)
        upd(ujung[i], cnt[i-j]);
    }
    for (int i = 1; i < b; ++i) {
      upd(ujung[i], cnt[i]);
    }
    dp2[0][0] = dp2[0][1] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j <= n && j - i < a; ++j) {
        upd(dp2[j][1], dp2[i][0]);
      }
      for (int j = i+1; j <= n && j - i < b; ++j) {
        int cost = (j == n || i == 0) ? ujung[j-i] : cnt[j-i];
        upd(dp2[j][0], 1LL * cost *  dp2[i][1] % mod);
      }
    }
    ans = (ans + dp[n] - dp2[n][1] - dp2[n][0]) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
