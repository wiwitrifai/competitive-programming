#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
const long long inf = 1e18;

long long dp[N][N];

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> d = a;
  d.push_back(0);
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  int m = d.size();
  dp[0][0] = 0;
  for (int i = 1; i < m; ++i)
    dp[0][i] = inf;
  for (int i = 0; i < n; ++i) {
    int now = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    for (int j = 0; j < m; ++j) {
      dp[i+1][j] = dp[i][j];
    }
    for (int j = m-2; j >= 0; --j) {
      dp[i+1][j] = min(dp[i+1][j], dp[i+1][j+1]);
    }
    for (int j = 1; j < m; ++j) {
      dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-1] + d[j] - d[j-1]);
    }
    for (int j = now + 1; j < m; ++j)
      dp[i+1][j] = inf;
    for (int j = 0; j < now; ++j)
      ++dp[i+1][j];
  }
  long long ans = inf;
  for (int i = 0; i < m; ++i)
    ans = min(ans, dp[n][i]);
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
