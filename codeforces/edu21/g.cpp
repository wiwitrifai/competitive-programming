#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int dp[2][N];
int to[N][26], p[N];
char s[N], t[N];

void prekmp(int m) {
  int j, i = 0;
  j = -1;
  p[0] = -1;
  while (i < m) {
    while (j >= 0 && t[i] != t[j]) {
      j = p[j];
    }
    j++; i++;
    p[i] = j;
  }
  for (int i = 0; i < m; i++) {
    to[i][t[i]] = i + 1;
    int now = p[i];
    for (int j = 0; j < 26; j++) {
      if (j == t[i]) continue;
      if (now < 0)
        to[i][j] = 0;
      else
        to[i][j] = to[now][j];
    }
  }
}

void upd(int &le, int ri) {
  if (le < ri) le = ri;
}

int main() {
  scanf("%s %s", s, t);
  int n = strlen(s), m = strlen(t);
  for (int i = 0; i < m; i++) t[i] -= 'a';
  prekmp(m);
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  int c = 0, b = 1;
  for (int i = 0; i < n; i++) {
    swap(c, b);
    fill(dp[c], dp[c]+m, -1);
    int fr = 0, til = 25;
    if (s[i] != '?')
      fr = til = s[i]-'a';
    for (int j = 0; j < m; j++) if (dp[b][j] != -1) {
      int cur = dp[b][j];
      for (int k = fr; k <= til; k++) {
        int nx = to[j][k];
        if (nx == m)
          upd(dp[c][p[nx]], cur+1);
        else
          upd(dp[c][nx], cur);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
    upd(ans, dp[c][i]);
  printf("%d\n", ans);
  return 0;
}