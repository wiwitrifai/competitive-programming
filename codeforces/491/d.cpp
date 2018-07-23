#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int dp[N][3];

char s[2][N];
int cnt[N];

int add(int a, int b) {
  if (a < 0 || b < 0) return -1;
  return a + b;
}

void upd(int & res, int a) {
  res = max(res, a);
}

int main() {
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < 2; ++i)
    scanf("%s", s[i]);
  int n = strlen(s[0]);
  dp[0][2] = 0;
  for (int i = 0; i < n; ++i) {
    cnt[i] = (s[0][i] == 'X') + (s[1][i] == 'X');
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int now = cnt[i];
    if (now == 0) {
      upd(dp[i+1][0], dp[i][0]);
      upd(dp[i+1][0], dp[i][1]);
      upd(dp[i+1][0], dp[i][2]);
      upd(dp[i+1][1], add(dp[i][0], 1));
      upd(dp[i+1][2], add(dp[i][0], 1));
      upd(dp[i+1][2], add(dp[i][1], 1));
    }
    else if (now == 1) {
      dp[i+1][0] = -1;
      upd(dp[i+1][1], dp[i][0]);
      upd(dp[i+1][1], dp[i][1]);
      upd(dp[i+1][1], dp[i][2]);
      upd(dp[i+1][2], add(dp[i][0], 1));
    }
    else {
      dp[i+1][0] = dp[i+1][1] = -1;
      upd(dp[i+1][2], dp[i][0]);
      upd(dp[i+1][2], dp[i][1]);
      upd(dp[i+1][2], dp[i][2]);
    }
    for (int j = 0; j < 3; ++j)
      upd(ans, dp[i+1][j]);
  }
  printf("%d\n",ans );
  return 0;
}