#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, K = 7;

int cnt[N];
int dp[2][K][K];


inline void upd(int & var, int x) {
  if (var < x)
    var = x;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ++cnt[a];
  }
  int c = 0, b = 1;

  for (int p = 0; p < K; ++p) {
    for (int q = 0; q < K; ++q) {
      dp[c][p][q] = -1;
    }
  }
  dp[c][0][0] = 0;
  for (int i = 1; i <= m; ++i) {
    swap(c, b);
    for (int p = 0; p < K; ++p) {
      for (int q = 0; q < K; ++q) {
        dp[c][p][q] = -1;
      }
    }
    for (int p = 0; p < K; ++p) {
      for (int q = 0; q < K; ++q) {
        int now = dp[b][p][q];
        if (now == -1) continue;
        int w = min(min(p, q), cnt[i]);
        for (int z = 0; z <= w; ++z) {
          int x = (cnt[i] - z)/3, r = cnt[i] - z - x * 3;
          upd(dp[c][q-z][r], now + x + z);
          if (x > 0 && r + 3 < K) {
            upd(dp[c][q-z][r+3], now + x + z -1);
            if (x > 1 && r + 6 < K) {
              upd(dp[c][q-z][r+6], now + x + z - 2);
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j)
      ans = max(dp[c][i][j], ans);
  }
  printf("%d\n", ans);
  return 0;
}