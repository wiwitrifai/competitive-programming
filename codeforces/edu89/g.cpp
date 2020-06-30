#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, inf = 1e9 + 7;

int dp[N][N];

char s[N], t[N];

void upd(int & var, int val) {
  if (var > val)
    var = val;
}

int main() {
  scanf("%s", s);
  scanf("%s", t);
  int n = strlen(s), m = strlen(t);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      upd(dp[i+1][j], dp[i][j] + 1);
      if (j + 1 <= m && s[i] == t[j])
        upd(dp[i+1][j+1], dp[i][j]);
    }
    if (s[i] != '.') {
      int skip = -1;
      for (int j = i, cnt = 0; j < n; ++j) {
        cnt += s[j] == '.' ? -1 : 1;
        if (cnt == 0) {
          skip = j - i + 1;
          break;
        }
      }
      if (skip != -1) {
        for (int j = 0; j <= m; ++j) {
          upd(dp[i+skip][j], dp[i][j]);
        }
      }
    }
  }
  printf("%d\n", dp[n][m]);
  return 0;
}
