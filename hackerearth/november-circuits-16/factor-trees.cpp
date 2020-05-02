#include <bits/stdc++.h>

using namespace std;

const int N = 5050, M = 505;

long long dp[N][M], all[N];
vector< int > fac[N];

int main() {
  for (int i = 2; i < N; i++) {
    for (int j = i + i; j < N; j += i)
      fac[j].push_back(i);
  }
  for (int i = 2; i < N; i++) {
    if (fac[i].empty()) {
      if (i < M) dp[i][i] = 1;
      all[i] = 1;
      continue;
    }
    all[i] = 0;
    for (int l = 0, r = (int)fac[i].size()-1; l <= r; l++, r--) {
      int u = fac[i][l], v = fac[i][r];
      if (u != v) {
        all[i] += all[u] * all[v];
        for (int x : fac[i]) if ((u % x) == 0 || (v % x) == 0) {
          if (x >= M) break;
          dp[i][x] += dp[u][x] * all[v] + (all[u] - dp[u][x]) * dp[v][x];
        } 
      }
      else {
        all[i] += (all[u] * (all[v] + 1))/2;
        for (int x : fac[i]) if ((u % x) == 0) {
          if (x >= M) break;
          dp[i][x] += dp[u][x] * (all[v] - dp[v][x]) + (dp[u][x] * (dp[u][x]+1))/2;
        }
      }
    }
    if (i < M) dp[i][i] = all[i];
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dp[i][j] += dp[i-1][j];
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int l, r, x;
    scanf("%d %d %d", &x, &l, &r);
    l--;
    printf("%lld\n", dp[r][x] - dp[l][x]);
  }
  return 0;
}