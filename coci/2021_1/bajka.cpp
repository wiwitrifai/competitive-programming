#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  string a, b;
  cin >> a >> b;
  vector<vector<int>> pos(26);
  for (int i = 0; i < n; ++i) {
    pos[a[i]-'a'].push_back(i);
  }
  const int inf = 1e9 + 7;
  vector<int> dp(n, inf), pre(n, inf);
  for (int x : pos[b[0]-'a']) {
    dp[x] = 0;
  }
  for (int i = 1; i < m; ++i) {
    char c = b[i] - 'a';
    dp.swap(pre);
    fill(dp.begin(), dp.end(), inf);
    for (int x : pos[c]) {
      if (x) {
        dp[x] = min(dp[x], pre[x-1]+1);
      }
      if (x + 1 < n) {
        dp[x] = min(dp[x], pre[x+1]+1);
      }
    }
    for (int x : pos[c]) {
      for (int y : pos[c]) {
        dp[x] = min(dp[x], dp[y] + abs(y-x));
      }
    }
  }
  int ans = *min_element(dp.begin(), dp.end());
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}
