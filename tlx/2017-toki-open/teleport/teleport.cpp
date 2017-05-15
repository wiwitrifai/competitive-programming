#include "teleport.h"

#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
const long long inf = 1e18;
long long dp[N][N];
void upd(long long & x, long long v) {
  x = max(x, v);
}

long long getMaximumPoints(int R, int C, int K,
    std::vector<std::vector<int> > T, std::vector<std::vector<int> > P) {
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      dp[i][j] = -inf;
  for (int i = 0; i < C; i++) {
    dp[0][i] = P[0][i];
  }
  for (int i = 1; i < R; i++) {
    for (int j = 0; j < C; j++) {
      for (int k = max(0, j-1); k <= min(C-1, j+1); k++) if (dp[i-1][k] > -inf)
        upd(dp[i][j], dp[i-1][k] + P[i][j]);
    }
  }
  long long ans = -inf;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (T[i][j])
        upd(ans, dp[i][j]);
  long long langsung = -inf;
  for (int i = 0; i < C; i++)
    upd(langsung, dp[R-1][i]);
  if (K == 0 || ans <= -inf)
    return langsung;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      dp[i][j] = -inf;
  long long rep = -inf;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      if (T[i][j]) {
        upd(dp[i][j], P[i][j]);
        upd(rep, dp[i][j]);
      }
      if (dp[i][j] == -inf) continue;
      if (i == R-1) continue;
      for (int k = max(0, j-1); k <= min(C-1, j+1); k++)
        upd(dp[i+1][k], dp[i][j] + P[i+1][k]);
    }
  long long fin = -inf;
  for (int i = 0; i < C; ++i) {
    upd(fin, dp[R-1][i]);
  }
  return max(langsung, ans + fin + max(rep * (K-1), 0LL));
}
