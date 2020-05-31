#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

char a[N], b[N];

int dp[N][N];

int cnta[N][26], cntb[N][26];

void calc(int n, char x[N], int cnt[N][26]) {
  memset(cnt[n], 0, sizeof cnt[n]);
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j)
      cnt[i][j] = cnt[i+1][j];
    ++cnt[i][x[i] - 'a'];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s %s", &n, a, b);
    calc(n, a, cnta);
    calc(n, b, cntb);
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = -1;
        if (i == 0 && j == 0)
          dp[i][j] = 0;
        if (i) {
          int c = a[i-1] - 'a';
          if (cnta[i][c] >= cntb[j][c])
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
        if (j) {
          dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
        if (i && j && a[i-1] == b[j-1] && dp[i-1][j-1] >= 0) {
          dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
      }
    }
    bool ok = 1;
    sort(a, a+n);
    sort(b, b+n);
    for (int i = 0; i < n; ++i)
      ok &= a[i] == b[i];
    int ans = -1;
    if (ok && dp[n][n] >= 0)
      ans = n - dp[n][n];
    printf("%d\n", ans);
  }
  return 0;
}
