#include <bits/stdc++.h>

using namespace std;

const int N = 303, mod = 1e9 + 7;

int dp[2][N][N];

vector< pair< int, int > > con[N];

void add(int & le, int ri) {
  le += ri;
  if (le >= mod) le -= mod;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    con[r].emplace_back(l, x);
  }
  int c = 0, b = 1;
  dp[0][0][0] = 3;
  for (auto it : con[1]) {
    if (it.second > 1) dp[0][0][0] = 0;
  }
  for (int i = 1; i < n; i++) {
    swap(b, c);
    memset(dp[c], 0, sizeof dp[c]);
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= j; k++) {
        if (dp[b][j][k] == 0) continue;
        int cur = dp[b][j][k];
        add(dp[c][j][k], cur);
        if (j > k) {
          add(dp[c][i][k], cur);
          if (k > 0)
            add(dp[c][i][j], cur);
          else
            add(dp[c][i][j], cur);
        }
        else
          add(dp[c][i][k], cur * 2 % mod);
      }
    }
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= j; k++) {
        if (dp[c][j][k] == 0) continue;
        bool ok = 1;
        for (auto c : con[i+1]) {
          int x = c.second, l = c.first;
          if (x == 1) {
            if (l <= j) ok = 0;
          }
          else if (x == 2) {
            if (l > j || l <= k) ok = 0;
          }
          else {
            if (l > k) ok = 0;
          }
          if (!ok) break;
        }
        if (!ok) dp[c][j][k] = 0;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      ans = (ans + dp[c][i][j]) % mod;
  cout << ans << endl;
  return 0;
}