#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> cnt(n+m, vector<int>(2, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      scanf("%d", &a);
      ++cnt[i+j][a];
    }
  }
  int ans = 0;
  int l = 0, r = n+m-2;
  while (l < r) {
    ans += min(cnt[l][0] + cnt[r][0], cnt[l][1] + cnt[r][1]);
    ++l;
    --r;
  }
  printf("%d\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
