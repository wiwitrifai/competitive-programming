#include <bits/stdc++.h>

using namespace std;

const int N = 80, inf = 1e7;

int dp[N][N][N][3], n;
char s[N];
int ck[N], cv[N], co[N];

void upd(int & res, int val, bool debug = 0) {
  res = min(res, val);
}

int main() {
  scanf("%d %s", &n, s);
  cerr << s << endl;
  ck[0] = cv[0] = co[0];
  for (int i = 0; i < n; i++) {
    ck[i+1] = ck[i] + (s[i] == 'K');
    cv[i+1] = cv[i] + (s[i] == 'V');
    co[i+1] = co[i] + ((s[i] != 'V') && (s[i] != 'K'));
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i][j][k][0] = dp[i][j][k][1] = inf;
      }
    } 
  }
  dp[0][0][0][0] = dp[0][0][0][1] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        int now = co[i] + cv[j] + ck[k];
        int addk = now - min(co[k], co[i]) - min(cv[k], cv[j]) - ck[k] + k;
        int addj = now - min(co[i], co[j]) - cv[j] - min(ck[j], ck[k]) + j;
        int addi = now - co[i] - min(cv[i], cv[j]) - min(ck[i], ck[k]) + i;
        if (dp[i][j][k][0] < inf) {
          if (k < n) {
            upd(dp[i][j][k+1][0], dp[i][j][k][0] + max(0, addk-now));
            if (s[k] != 'K')
              upd(dp[i][j][k+1][0], dp[i][j][k][0]);
          }
          if (j < n) {
            upd(dp[i][j+1][k][1], dp[i][j][k][0] + max(0, addj-now));
            if (s[j] != 'V')
              upd(dp[i][j+1][k][0], dp[i][j][k][0]);
          }
          if (i < n) {
            upd(dp[i+1][j][k][0], dp[i][j][k][0] +  max(0, addi-now));
            if (s[i] == 'K' || s[i] == 'V')
              upd(dp[i+1][j][k][0], dp[i][j][k][0]);
          }
        }
        if (dp[i][j][k][1] < inf) {
          if (j < n) {
            upd(dp[i][j+1][k][1], dp[i][j][k][1] + max(0, addj-now));
            if (s[j] != 'V')
              upd(dp[i][j+1][k][1], dp[i][j][k][1]);
          }
          if (i < n) {
            if ((s[i] != 'K') && (s[i] != 'V'))
              upd(dp[i+1][j][k][0], dp[i][j][k][1] + max(0, addi-now));
            if (s[i] == 'K' || s[i] == 'V')
              upd(dp[i+1][j][k][1], dp[i][j][k][1]);
          }
        }
      }
    } 
  }
  printf("%d\n", min(dp[n][n][n][0], dp[n][n][n][1]));
  return 0;
}