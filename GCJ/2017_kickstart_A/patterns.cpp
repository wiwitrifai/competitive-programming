#include <bits/stdc++.h>

using namespace std;

const int N = 8080;

bool dp[N][N];
char a[N], b[N], s[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n, m, len;
    scanf("%s", s);
    len = strlen(s);
    n = 0;
    for (int i= 0; i < len; i++) {
      if (s[i] == '*') {
        for (int j = 0; j < 4; j++) a[n++] = '?';
      }
      else
        a[n++] = s[i];
    }
    scanf("%s", s);
    len = strlen(s);
    m = 0;
    for (int i= 0; i < len; i++) {
      if (s[i] == '*') {
        for (int j = 0; j < 4; j++) b[m++] = '?';
      }
      else
        b[m++] = s[i];
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (!dp[i][j]) continue;
        if (a[i] == '?')
          dp[i+1][j] = dp[i+1][j+1] = 1;
        if (b[j] == '?')
          dp[i][j+1] = dp[i+1][j+1] = 1;
        if (i < n && j < m && a[i] == b[j])
          dp[i+1][j+1] = 1;
      }
    }
    printf("Case #%d: %s\n", tc, dp[n][m] ? "TRUE" : "FALSE");
  }

  return 0;
}