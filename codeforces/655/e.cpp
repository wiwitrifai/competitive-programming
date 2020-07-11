#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<pair<int, int>>> intervals(m);
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int l, r;
      scanf("%d %d", &l, &r);
      --l, --r;
      for (int c = l; c <= r; ++c)
        intervals[c].emplace_back(l, r);
    }
  }
  vector<vector<int>> dp(m, vector<int>(m, 0));
  for (int len = 1; len <= m; ++len) {
    for (int l = 0; l + len <= m; ++l) {
      int r = l + len - 1;
      for (int mid = l; mid <= r; ++mid) {
        int cnt = 0;
        for (auto & e : intervals[mid])
          cnt += l <= e.first && e.second <= r;
        cnt *= cnt;
        if (l < mid)
          cnt += dp[l][mid-1];
        if (mid < r)
          cnt += dp[mid+1][r];
        dp[l][r] = max(dp[l][r], cnt);
      }
    }
  }
  printf("%d\n", dp[0].back());
  return 0;
}
