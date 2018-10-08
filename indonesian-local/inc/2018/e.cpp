#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int dp2[N][10][4], n;
int dp[N][10];
int s[N];
int cnt[10];

void upd(int & var, int val) {
  if (var > val)
    var = val;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", s+i), ++cnt[s[i]];
  int superb = inf;
  for (int i = 0; i < 10; ++i)
    superb = min(superb, n - cnt[i]);
  for (int i = 0; i < 10; ++i) {
    dp[0][i] = s[0] != i;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      dp[i][j] = dp[i-1][j];
      if (j > 0) {
        dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
      }
      if (j < 9) {
        dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
      }
      dp[i][j] += j != s[i];
    }
  }
  int great = inf;
  for (int i = 0; i < 10; ++i)
    great = min(great, dp[n-1][i]);

  for (int i = 0; i < 10; ++i) {
    dp2[0][i][0] = (i != s[0]);
    dp2[0][i][1] = dp2[0][i][2] = inf;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 1; k < 3; ++k) {
        dp2[i][j][k] = dp2[i-1][j][k-1];
        if (j > 0)
          upd(dp2[i][j][k], dp2[i-1][j-1][k-1]);
        if (j < 9)
          upd(dp2[i][j][k], dp2[i-1][j+1][k-1]);
      }
      dp2[i][j][0] = inf;
      dp2[i][j][2] = min(dp2[i][j][2], dp2[i-1][j][2]);
      if (j > 0)
        upd(dp2[i][j][2], dp2[i-1][j-1][2]);
      if (j < 9)
        upd(dp2[i][j][2], dp2[i-1][j+1][2]);
    }
    int mi = inf;
    for (int j = 2; j <= 9; ++j) {
      mi = min(mi, dp2[i-1][j-2][2]);
      upd(dp2[i][j][0], mi);
    }
    mi = inf;
    for (int j = 7; j >= 0; --j) {
      mi = min(mi, dp2[i-1][j+2][2]);
      upd(dp2[i][j][0], mi);
    }
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 3; ++k) {
        dp2[i][j][k] += j != s[i];
      }
    }
  }
  int good = inf;
  for (int i = 0; i < 10; ++i)
    upd(good, dp2[n-1][i][2]);
  printf("%d %d %d\n", good, great, superb);
  return 0;
}