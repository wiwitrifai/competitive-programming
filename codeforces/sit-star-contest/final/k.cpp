#include <bits/stdc++.h>

using namespace std;

const int N = 2020, inf = 1e9 + 7;

int t[N], d[N];
int dp[N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", t+i, d+i);
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [](int i, int j) {
    return max(t[i]+d[i], t[i] + t[j]+d[j]) < max(t[j]+d[j], t[j] + t[i]+d[i]);
  });
  reverse(id.begin(), id.end());
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= k; ++j)
      dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int x = id[i];
    for (int j = 0; j <= k; ++j) {
      dp[i+1][j] = dp[i][j];
      if (j) {
        dp[i+1][j] = min(dp[i+1][j], max(dp[i][j-1], d[x]) + t[x]);
      }
    }
  }
  int j = k;
  vector<int> ans;
  for (int i = n-1; i >= 0 && j > 0; --i) {
    int x = id[i];
    if (max(dp[i][j-1], d[x]) + t[x] == dp[i+1][j]) {
      ans.push_back(x);
      --j;
    }
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i]+1, i+1 == (int)ans.size() ? '\n' : ' ');
  }
  return 0;
}
