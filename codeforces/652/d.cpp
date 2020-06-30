#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6, mod = 1e9 + 7;

int dp[N];
bool full[N];

void solve() {
  int n;
  scanf("%d", &n);
  printf("%d\n", dp[n]);
}

int main() {
  full[3] = true;
  dp[3] = 4;
  for (int i = 4; i < N; ++i) {
    dp[i] = dp[i-1];
    dp[i] += dp[i-2];
    if (dp[i] >= mod)
      dp[i] -= mod;
    dp[i] += dp[i-2];
    if (dp[i] >= mod)
      dp[i] -= mod;
    if (!full[i-1] && !full[i-2]) {
      dp[i] += 4;
      full[i] = true;
      if (dp[i] >= mod)
        dp[i] -= mod;
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
