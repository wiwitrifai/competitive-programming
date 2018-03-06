#include <bits/stdc++.h>

using namespace std;

const int N = 555, inf = 1e9 + 7;

int dp[N][N];

char s[N];
int ma[N];
int cnt[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= k; ++j)
      dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j) s[j] -= '0';
    int tot = 0;
    for (int j = 0; j < m; ++j) tot += s[j];
    for (int j = 0; j <= m; ++j)
      ma[j] = cnt[j] = 0;
    for (int j = 0; j < m; ++j) {
      for (int z = 1; z <= m; ++z) {
        cnt[z] += s[j];
        if (j >= z)
          cnt[z] -= s[j-z];
        ma[z] = max(ma[z], cnt[z]);
      }
    }
    for (int j = 0; j <= k; ++j) {
      if (dp[i][j] >= inf) continue;
      for (int z = 0; z <= m; ++z) {
        int bolos = tot - ma[z];
        if (bolos + j <= k) {
          dp[i+1][bolos+j] = min(dp[i+1][bolos+j], dp[i][j] + z);
        }
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= k; ++i)
    ans = min(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}