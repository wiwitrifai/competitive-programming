#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, K = 1e4 + 4;

long long dp[K];
int inv[K];

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int k;
long long calc(long long d, int cnt) {
  memset(dp, 0, sizeof dp);
  dp[cnt] = 1;
  for (int i = 0; i < k; ++i) {
    long long sum = 0;
    for (int j = cnt; j >= 0; --j) {
      sum = (sum + 1LL * dp[j] * inv[j+1]) % mod;
      dp[j] = sum;
    }
  }
  long long cur = 1, ans = 0;
  for (int i = 0; i <= cnt; ++i) {
    ans = (ans + cur * dp[i]) % mod;
    cur = cur * d % mod;
  }
  // cerr << d << " " << cnt << " " << ans << endl;
  return ans;
}

int main() {
  for (int i = 1; i < K; ++i)
    inv[i] = powmod(i, mod - 2);
  long long n;
  scanf("%lld %d", &n, &k);
  long long ans = 1;
  for (long long d = 2; d * d <= n; ++d) {
    if (n % d) continue;
    int cnt = 0;
    while ((n % d) == 0) {
      n /= d;
      ++cnt;
    }
    ans = ans * calc(d, cnt) % mod;
  }
  if (n > 1) {
    ans = ans * calc(n, 1) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}