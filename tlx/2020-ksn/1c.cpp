#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5, K = 404, inf = 1 << 29;

int h[N], cnt[N];
int dp[N][K];
int to[N][K], s[N];

inline void upd(int & var, int val) {
  if (var > val)
    var = val;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", &h[i]), --h[i];
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= k; ++j)
      dp[i][j] = inf;
  dp[0][0] = 0;
  memset(to, -1, sizeof to);
  for (int z = 0; z <= k; ++z) {
    int cost = z;
    for (int i = 0, r = 0; i < n; ++i) {
      while (r < n) {
        int x = h[r];
        int c = cnt[x] >= m;
        if (c <= cost) {
          cost -= c;
          ++cnt[x];
          ++r;
        } else {
          break;
        }
      }
      if (cnt[h[r-1]] <= m && cost == 0) {
        to[i][s[i]] = (r << 9) | z;
        ++s[i];
      }
      int x = h[i];
      cost += cnt[x] > m;
      --cnt[x];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (dp[i][j] >= inf) continue;
      int now = dp[i][j] + 1;
      int til = s[i];
      for (int d = 0; d < til; ++d) {
        int r = to[i][d];
        int z = r & 511;
        z += j;
        if (z > k) break;
        r >>= 9;
        upd(dp[r][z], now);
      }
      int z = j + 1;
      if (z <= k) {
        upd(dp[i+1][z], dp[i][j]);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= k; ++i) {
    upd(ans, dp[n][i]);
  }
  printf("%d\n", ans);
  return 0;
}
