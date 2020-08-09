#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, inf = 1e9 + 7;

char buffer[N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    s[i] = buffer;
  }
  if (n >= 4 && m >= 4) {
    puts("-1");
    return;
  }
  if (n < 2 || m < 2) {
    puts("0");
    return;
  }
  if (m > n) {
    vector<string> tmp(m);
    for (int j = 0; j < m; ++j) {
      tmp[j].resize(n);
      for (int i = 0; i < n; ++i)
        tmp[j][i] = s[i][j];
    }
    s = tmp;
    swap(n, m);
  }
  int nmask = 1 << m;
  vector<int> dp(nmask, inf);
  vector<vector<bool>> invalid(nmask, vector<bool>(nmask, false));
  vector<vector<int>> transisi(nmask);
  for (int i = 0; i < nmask; ++i) {
    for (int j = 0; j < nmask; ++j) {
      for (int k = 0; k + 1 < m; ++k) {
        int cnt = ((i >> k) & 1) + ((j >> k) & 1);
        cnt += ((i >> (k+1)) & 1) + ((j >> (k+1)) & 1);
        if ((cnt & 1) == 0) {
          invalid[i][j] = true;
          break;
        }
      }
      if (!invalid[i][j])
        transisi[j].push_back(i);
    }
  }
  auto get_mask = [&](int row) {
    int mask = 0;
    for (int i = 0; i < m; ++i) {
      if (s[row][i] == '0') continue;
      mask |= (1 << i);
    }
    return mask;
  };
  int cur = get_mask(0);
  for (int i = 0; i < nmask; ++i)
    dp[i] = __builtin_popcount(cur ^ i);
  auto pre = dp;
  for (int i = 1; i < n; ++i) {
    pre = dp;
    cur = get_mask(i);
    for (int j = 0; j < nmask; ++j) {
      int cost = __builtin_popcount(cur ^ j);
      dp[j] = inf;
      for (int x : transisi[j])
        dp[j] = min(dp[j], pre[x] + cost);
    }
  }
  int ans = inf;
  for (int i = 0; i < nmask; ++i) {
    ans = min(ans, dp[i]);
  }
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
