#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

char s[N];

int dp[2][2][2];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  int cur = 0, bef = 1;
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; ++i) {
    swap(cur, bef);
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        dp[cur][j][k] = inf;
      }
    }
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (dp[bef][j][k] >= inf) continue;
        for (int z = 0; z < 2; ++z) {
          bool ok = true;
          if (i >= 2 && !j && !z && s[i-2] == s[i]) {
            ok = false;
          }
          if (i >= 1 && !k && !z && s[i-1] == s[i]) {
            ok = false;
          }
          if (ok) {
            dp[cur][k][z] = min(dp[cur][k][z], dp[bef][j][k] + z);
          }
        }
      }
    }
  }
  int ans = inf;
  for (int j = 0; j < 2; ++j) {
    for (int k = 0; k < 2; ++k) {
      ans = min(ans, dp[cur][j][k]);
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
