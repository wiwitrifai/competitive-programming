#include <bits/stdc++.h>

using namespace std;

const int N = 303, Q = 105, S = 1002, mod = 1e9 + 7;

int dp[N][N][Q];
int x[N][N], C[N][N];

inline void add(int & a, int v) {
  a += v;
  if (a >= mod)
    a -= mod;
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
  }
  int r, c, n;
  scanf("%d %d %d", &r, &c, &n);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      scanf("%d", x[i]+j);
    }
  }
  if (x[0][0] < Q)
    dp[0][0][x[0][0]] = 1;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      for (int k = 1; k < Q; ++k) {
        if (dp[i][j][k] == 0) continue;
        int cur = dp[i][j][k];
        int mul;
        if (i+1 < r && (mul = x[i+1][j] * k) < Q) {
          add(dp[i+1][j][mul], cur);
        }
        if (j+1 < c && (mul = x[i][j+1] * k) < Q) {
          add(dp[i][j+1][mul], cur);
        }
      }
    }
  }
  // cerr << r << " " << c << " " << C[r][c] << endl;
  int ans = C[r + c - 2][c-1];
  // cerr << ans << endl;
  for (int i = 0; i < min(Q, n); ++i) {
    add(ans, mod - dp[r-1][c-1][i]);
    // cerr << i << " = " <<  dp[r-1][c-1][i] << endl;
  }
  // if (n <= Q) {
    printf("%d\n", ans);
    return 0;
  // }

  return 0;
}