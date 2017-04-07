#include <bits/stdc++.h>

using namespace std;

const int N = 16, M = 105, inf = 1e9 + 7;

int dp[1<<N][N];
int x[N][M], m[N];
int to[15][15];
bool live[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", m+i);
    for (int j = 0; j < m[i]; j++) {
      scanf("%d", x[i]+j);
    }
    live[i] = 1;
  } 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n && live[i]; j++) {
      if (j == i) continue;
      if (!live[j]) continue;
      for (int k = 0; k+m[i] <= m[j] && live[i]; k++) {
        live[i] = 0;
        for (int z = 0; z < m[i]; z++)
          if (x[i][z] != x[j][k+z]) {
            live[i] = 1;
            break;
          }
      }
    } 
  }
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (!live[i]) continue;
    m[k] = m[i];
    for (int j = 0; j < m[i]; j++) {
      x[k][j] = x[i][j];
    }
    k++;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if (i == j) continue;
      to[i][j] = m[j];
      for (int z = 0; z < m[i]; z++) {
        if (z + m[j] <= m[i]) continue;
        bool ok = 1;
        for (int p = z; p < m[i]; p++) {
          if (x[i][p] != x[j][p-z]) {
            ok = 0;
            break;
          }
        } 
        if (ok) {
          to[i][j] = m[j] - (m[i]-z);
          break;
        }
      }
    }
  }
  for (int i = 0; i < (1<<k); i++)
    for (int j = 0; j < k; j++)
      dp[i][j] = inf;
  for (int i = 0; i < k; i++)
    dp[1<<i][i] = m[i];
  for (int mask = 0; mask < (1<<k); mask++) {
    for (int i = 0; i < k; i++) if (mask & (1<<i)) {
      for (int j = 0; j < k; j++) if ((mask & (1<<j)) == 0) {
        int nmask = mask | (1<<j);
        dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + to[i][j]);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < k; i++)
    ans = min(ans, dp[(1<<k)-1][i]);
  cout << ans << endl;
  return 0;
}