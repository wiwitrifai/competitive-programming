#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char a[N], b[N];

int dp[2][N][N];
int go[N][2];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s %s", a, b);
  for (int i = 0; i < n; ++i) {
    a[i] -= '0';
  }
  for (int i = 0; i < m; ++i) {
    b[i] -= '0';
  }
  vector<int> pre(m, 0);
  for(int i = 1; i < m; i++) {
    int j = pre[i - 1];
    while(j > 0 && b[i] != b[j]) j = pre[j - 1];
    if(b[i] == b[j]) pre[i] = j + 1;
  }
  go[0][b[0]] = 1;
  for (int i = 1; i < m; ++i) {
    go[i][0] = go[i][1] = i+1;
    int wrong = b[i] ^ 1;
    go[i][wrong] = go[pre[i-1]][wrong];
  }
  int cur = 0, bef = 1;
  memset(dp[cur], -1, sizeof dp[cur]);
  auto upd = [&](int & var, int val) {
    if (val < 0)
      return;
    if (var == -1 || var > val)
      var = val;
  };
  dp[cur][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int now = a[i], other = now^1;
    swap(cur, bef);
    memset(dp[cur], -1, sizeof dp[cur]);
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        int val = dp[bef][j][k];
        if (val < 0) continue;
        upd(dp[cur][go[j][now]][k], val);
        upd(dp[cur][go[j][other]][k], val+1);
      }
    }
    for (int k = 0; k < n; ++k) {
      upd(dp[cur][pre[m-1]][k+1], dp[cur][m][k]);
    }
  }
  for (int k = 0; k < n - m + 2; ++k) {
    int ans = -1;
    for (int j = 0; j < m; ++j) {
      upd(ans, dp[cur][j][k]);
    }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}
