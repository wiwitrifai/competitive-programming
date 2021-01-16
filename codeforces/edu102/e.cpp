#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;


vector<pair<int, int>> g[N];
long long ans[N][4];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j)
      ans[i][j] = inf;
  }
  ans[0][0] = 0;
  priority_queue<pair<long long, int>> pq;
  pq.emplace(0, 0);
  auto upd = [&](int u, int mask, long long cur) {
    if (cur < ans[u][mask]) {
      ans[u][mask] = cur;
      pq.emplace(-cur, (u << 2) | mask);
    }
  };
  while (!pq.empty()) {
    int v = pq.top().second;
    long long dist = -pq.top().first;
    pq.pop();
    int mask = v & 3;
    v >>= 2;
    if (ans[v][mask] != dist) {
      continue;
    }
    for (auto & e : g[v]) {
      int u = e.first, w = e.second;
      long long cur = dist + w;
      upd(u, mask, cur);
      if ((mask & 1) == 0) {
        upd(u, mask | 1, dist);
      }
      if ((mask & 2) == 0) {
        upd(u, mask | 2, cur + w);
      }
      if ((mask & 3) == 0) {
        upd(u, mask | 3, cur);
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    printf("%lld%c", ans[i][3], i+1 == n ? '\n' : ' ');
  }
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
