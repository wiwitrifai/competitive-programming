#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, K = 19;
const long long inf = 1e18;

vector<pair<int, int>> g[N];

long long dist[N][K];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= k; ++j)
      dist[i][j] = inf;
  dist[0][0] = 0;
  priority_queue<pair<long long, int>> pq;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    long long now = -pq.top().first;
    int v = pq.top().second;
    pq.pop();
    int lv = v & 31;
    v >>= 5;
    if (dist[v][lv] != now) continue;
    for (auto e : g[v]) {
      int u = e.first, w = e.second;
      int cur = now + w;
      if (cur < dist[u][lv]) {
        dist[u][lv] = cur;
        pq.emplace(-cur, (u << 5) | lv);
      }
    }
    if (lv == k) continue;
    ++lv;
    if (dist[v][lv] > now) {
      dist[v][lv] = now;
      pq.emplace(-now, (v << 5) | lv);
    }

    for (auto e : g[v]) {
      int u = e.first;
      if (now < dist[u][lv]) {
        dist[u][lv] = now;
        pq.emplace(-now, (u << 5) | lv);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", dist[i][k], i+1 == n ? '\n' : ' ');
  }
  return 0;
}
