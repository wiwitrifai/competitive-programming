#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, mod = 1e9 + 7;
int dp[N], sum[N];

char s[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  bool same = 1;
  for (int i = 0; i < m; ++i)
    if (s[i] != s[0])
      same = 0;
  if (same) {
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i-1];
      if (i > 1)
        dp[i] = (dp[i] + dp[i-2]) % mod;
    }
    int ans = (dp[n] + dp[n-2]) % mod;
    printf("%d\n", ans);
    return 0;
  }
  int cnt = 0;
  while (s[cnt] == s[0]) ++cnt;
  if ((cnt & 1) == 0)
    ++cnt;
  int cur = 0;
  for (int i = 0; i < m; ++i) {
    if (s[i] != s[0]) {
      if (cur & 1) {
        cnt = min(cnt, cur);
      }
      cur = 0;
    }
    else {
      ++cur;
    }
  }
  dp[0] = 1;
  sum[0] = 1;
  for (int i = 2; i <= n; i += 2) {
    dp[i] = sum[i-2] - (i - (cnt+3) >= 0 ? sum[i - (cnt+3)] : 0);
    dp[i] %= mod;
    if (dp[i] < 0)
      dp[i] += mod;
    sum[i] = (dp[i] + sum[i-2]) % mod;
  }
  int ans = dp[n];
  for (int i = 2; i <= n && i <= cnt+1; i += 2) {
    ans = (ans + 1LL * dp[n-i] * (i-1)) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
