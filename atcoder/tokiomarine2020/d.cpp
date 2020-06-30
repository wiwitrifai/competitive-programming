#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, S = 1 << 9;

int n, q, v[(1 << 18) + 5], w[(1 << 18) + 5];

int dp[S][N];
pair<int, int> val[22];
int sw[S + 5], sv[S + 5];

void calc(int u) {
  if (dp[u][0] != -1) return;
  int len = 0;
  int ver = u;
  while (ver) {
    val[len++] = {v[ver], w[ver]};
    ver /= 2;
  }
  int nmask = 1 << len;
  dp[u][0] = 0;
  sw[0] = sv[0] = 0;
  for (int mask = 1; mask < nmask; ++mask) {
    int p = __builtin_ctz(mask), bef = mask ^ (1 << p);
    int ww = sw[bef] + val[p].second;
    int vv = sv[bef] + val[p].first;
    sw[mask] = ww;
    sv[mask] = vv;
    if (ww < N)
      dp[u][ww] = max(dp[u][ww], vv);
  }
  int now = 0;
  for (int i = 0; i < N; ++i) {
    now = max(dp[u][i], now);
    dp[u][i] = now;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", v+i, w+i);
  }
  memset(dp, -1, sizeof dp);
  scanf("%d", &q);
  while (q--) {
    int u, l;
    scanf("%d %d", &u, &l);
    int ans = 0;
    if (u < S) {
      calc(u);
      ans = dp[u][l];
    } else {
      int x = u;
      while (x >= S) x /= 2;
      calc(x);
      int len = 0;
      while (u >= S) {
        val[len++] = {v[u], w[u]};
        u /= 2;
      }
      ans = dp[u][l];
      int nmask = 1 << len;
      for (int mask = 1; mask < nmask; ++mask) {
        int p = __builtin_ctz(mask), bef = mask ^ (1 << p);
        int ww = sw[bef] + val[p].second;
        int vv = sv[bef] + val[p].first;
        sw[mask] = ww;
        sv[mask] = vv;
        if (ww <= l)
          ans = max(ans, vv + dp[u][l-ww]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
