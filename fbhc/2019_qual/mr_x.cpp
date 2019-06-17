#include <bits/stdc++.h>

using namespace std;

const int N = 333, inf = 1e9 + 7;
char s[N];

int dp[N][N][4];

void upd(int & var, int val) {
  if (var > val)
    var = val;
}

void solve(int tc) {
  printf("Case #%d: ", tc);
  scanf("%s", s);
  int n = strlen(s);
  assert(n <= 300);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k < 4; ++k)
        dp[i][j][k] = inf;
  for (int i = 0; i < n; ++i) {
    for (int f = 0; f < 4; ++f)
      dp[i][i][f] = 1;
    if (s[i] == '0')
      dp[i][i][0] = 0;
    else if (s[i] == '1')
      dp[i][i][3] = 0;
    else if (s[i] == 'x')
      dp[i][i][1] = 0;
    else if (s[i] == 'X')
      dp[i][i][2] = 0;
  }
  for (int len = 5; len <= n; ++len) {
    for (int lef = 0; lef + len <= n; ++lef) {
      int rig = lef + len - 1;
      int match_cost = (s[lef] != '(') + (s[rig] != ')');
      for (int mid = lef+2; mid + 2 <= rig; ++mid) {
        int cost = match_cost + (s[mid] != '|');
        for (int a = 0; a < 4; ++a) {
          for (int b = 0; b < 4; ++b) {
            upd(dp[lef][rig][a|b], dp[lef+1][mid-1][a] + dp[mid+1][rig-1][b] + cost);
          }
        }
        cost = match_cost + (s[mid] != '&');
        for (int a = 0; a < 4; ++a) {
          for (int b = 0; b < 4; ++b) {
            upd(dp[lef][rig][a&b], dp[lef+1][mid-1][a] + dp[mid+1][rig-1][b] + cost);
          }
        }
        cost = match_cost + (s[mid] != '^');
        for (int a = 0; a < 4; ++a) {
          for (int b = 0; b < 4; ++b) {
            upd(dp[lef][rig][a^b], dp[lef+1][mid-1][a] + dp[mid+1][rig-1][b] + cost);
          }
        }
      }
    }
  }
  int ans = min(dp[0][n-1][0], dp[0][n-1][3]);
  printf("%d\n", ans);
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
    fflush(stdout);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
