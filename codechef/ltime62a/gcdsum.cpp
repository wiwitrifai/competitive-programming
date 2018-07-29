#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int dp[N], cnt[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i < N; ++i)
    dp[i] = 1;
  long long tot = 0;
  for (int i = 0; i < n; ++i) {
    memset(cnt, 0, sizeof cnt);
    for (int j = 0; j < m; ++j) {
      int a;
      scanf("%d", &a);
      ++cnt[a];
      tot = (tot + a) % mod;
    }
    for (int j = 1; j < N; ++j) {
      for (int k = j+j; k < N; k += j)
        cnt[j] += cnt[k];
    }
    for (int j = 1; j < N; ++j) {
      dp[j] = (1LL * dp[j] * (1 + cnt[j])) % mod; 
    }
  }
  long long ans = 0;
  for (int i = N-1; i > 0; --i) {
    --dp[i];
    for (int j = i+i; j < N; j += i) {
      dp[i] = (dp[i] + mod - dp[j]) % mod;
    }
    dp[i] %= mod;
    if (dp[i] < 0)
      dp[i] += mod;
    ans = (ans + 1LL * i * dp[i]) % mod;
  }
  ans = (ans + mod - tot) % mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);

  return 0;
}