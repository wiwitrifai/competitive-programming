#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1024;
int dp[2][N];
int to[N][10];

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      int id = j;
      while (id < 10) {
        if (i & (1<<id))
          break;
        id++;
      }
      if (id >= 10)
        to[i][j] = i | (1<<j);
      else
        to[i][j] = i ^ (1<<id) ^ (1<<j);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    if (n == 1) {
      puts("10");
      continue;
    }
    memset(dp, 0, sizeof dp);
    if (x == 1) {
      for (int i = 1; i < 10; i++)
        dp[0][1<<i] = 1;
    }
    for (int i = 1; i < n; i++) {
      int c = i & 1, b = c ^ 1;
      scanf("%d", &x);
      x--;
      memset(dp[c], 0, sizeof dp[c]);
      for (int j = 0; j < N; j++) {
        int cnt = __builtin_popcount(j);
        if (cnt < x)
          continue;
        if (dp[b][j] == 0)
          continue;
        cnt = 0;
        for (int k = 0; k < 10; k++) {
          if (cnt == x) {
            int & now = dp[c][to[j][k]];
            now += dp[b][j];
            if (now >= mod)
              now -= mod;
          }
          if (j & (1<<k)) {
            cnt++;
            if (cnt > x)
              break;
          }
        }
      } 
    }
    int c = (n & 1) ^ 1;
    int ans = 0;
    for (int i = 0; i < N; i++) {
      ans += dp[c][i];
      if (ans >= mod)
        ans -= mod;
    }
    if (ans < 0)
      ans += mod;
    printf("%d\n", ans);
  }
  return 0;
}