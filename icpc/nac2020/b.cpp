#include <bits/stdc++.h>

using namespace std;

char board[10][10];
vector<int> trans[10], ship;
int n, k, must;
int enc(int x, int y) {
  return x * n + y;
}

int dp[2][1 << 25];

int main() {
  scanf("%d %d", &n, &k);
  must = 0;
  int mask = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", board[i]);
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == 'X') {
        mask |= 1 << enc(i, j);
      }
      else if (board[i][j] == 'O') {
        must |= 1 << enc(i, j);
      }
    }
  }
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i + len <= n) {
          int m = 0;
          for (int z = 0; z < len; ++z) {
            m |= 1 << enc(i+z, j);
          }
          if ((m & mask) == 0)
            trans[len].push_back(m);
        }
        if (j + len <= n) {
          int m = 0;
          for (int z = 0; z < len; ++z) {
            m |= 1 << enc(i, j+z);
          }
          if ((m & mask) == 0)
            trans[len].push_back(m);
        }
      }
    }
    sort(trans[len].begin(), trans[len].end());
    trans[len].erase(unique(trans[len].begin(), trans[len].end()), trans[len].end());
  }
  ship.resize(k);
  for (int i = 0; i < k; ++i)
    scanf("%d", &ship[i]);
  memset(dp, 0, sizeof dp);
  int c = 0, b = 1;
  dp[c][mask] = 1;
  int nmask = 1 << (n * n);
  for (int x : ship) {
    swap(c, b);
    memset(dp[c], 0, sizeof dp[c]);
    for (int m = mask; m < nmask; m = (m+1) | mask) {
      if (dp[b][m] == 0) continue;
      for (int s : trans[x]) {
        if (s & m) continue;
        dp[c][m | s] += dp[b][m];
      }
    }
  }
  int ans = 0;
  for (int m = 0; m < nmask; ++m) {
    if ((m & must) == must) {
      ans += dp[c][m];
    }
  }
  printf("%d\n", ans);

  return 0;
}
