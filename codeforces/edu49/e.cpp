#include <bits/stdc++.h>

using namespace std;

const int N = 505, mod = 998244353;

int dp[N];
int cnt[N];

inline void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    dp[0] = 1;
    int sum = 1;
    for (int j = 1; j <= n; ++j) {
      dp[j] = sum;
      add(sum, dp[j]);
      if (j - i >= 0)
        add(sum, mod - dp[j-i]);
    }
    cnt[i] = dp[n];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j)
      add(cnt[j], mod-cnt[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n && i * j < k; ++j) {
      add(ans, 1LL * cnt[i] * cnt[j] % mod);
    }
  }
  add(ans, ans);
  printf("%d\n", ans);
  
  return 0;
}