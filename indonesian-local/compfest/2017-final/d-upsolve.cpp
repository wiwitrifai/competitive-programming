/**
 * Upsolve after contest
 * Author  : Wiwit Rifa'i
 * Problem : D - Xor-or
 * Status  : ?
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, cnt[2], col[N];
vector<pair<int, int> > g[N];

bool dfs(int v, int mask, int now = 0) {
  if (col[v] != -1) {
    return col[v] == now;
  }
  col[v] = now;
  if (now)
    cnt[1]++;
  else
    cnt[0]++;
  bool ok = 1;
  for (auto it : g[v]) {
    ok &= dfs(it.first, mask, now ^ (mask & it.second));
  }
  return ok;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    long long ans = 0;
    for (int mask = 1 << 30; mask; mask >>= 1) {
      fill(col, col+n, -1);
      for (int i = 0; i < n; i++) if (col[i] == -1) {
        cnt[0] = cnt[1] = 0;
        if (dfs(i, mask))
          ans += 1LL * mask * cnt[0] * cnt[1];
        else {
          int all = cnt[0] + cnt[1];
          ans += 1LL * mask * all * (all-1) / 2;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}