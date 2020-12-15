#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e9 + 7;

int dp[2][N];

char s[N][12];

inline void upd(int & var, int val) {
  if (var > val)
    var = val;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int j = 0; j < m; ++j) {
    s[0][j] = '.';
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i]+1);
    s[i][0] = '.';
  }
  int nmask = 1 << m;
  auto reset_dp = [&](int c) {
    fill(dp[c], dp[c] + nmask, inf);
  };
  int c = 0, b = 1;
  reset_dp(0);
  reset_dp(1);
  dp[c][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j+1] != '#') continue;
      swap(c, b);
      reset_dp(c);
      for (int mask = 0; mask < nmask; ++mask) {
        if (dp[b][mask] >= inf) continue;
        int other = mask & (~(1 << j));
        int val = dp[b][mask] + 1;
        if (j > 0 && s[i][j] == '#' && (mask & (1 << (j-1))) == 0) {
          --val;
        }
        upd(dp[c][other], val);
        val = dp[b][mask] + 1;
        if (s[i-1][j+1] == '#' && (mask & (1 << j)) != 0) {
          --val;
        }
        upd(dp[c][other|(1 << j)], val);
      }
    }
  }
  int ans = *min_element(dp[c], dp[c]+nmask);
  printf("%d\n", ans);
  return 0;
}
