#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair<int, int>> g[N];
long long dist[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i= 0; i < m; ++i) {
    int u, v, h;
    scanf("%d %d %d", &u, &v, &h);
    --u, --v;
    g[u].emplace_back(v, h);
    g[v].emplace_back(u, h);
  }
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    while (t--) {
      int c;
      scanf("%d", &c);
      --c;
      g[c+n].emplace_back(i, 0);
    }
  }
  for (int i = 0; i < k; ++i) {
    int p;
    scanf("%d", &p);
    for (auto it : g[i+n]) {
      int v = it.first;
      g[v].emplace_back(i+n, p);
    }
  }
  fill(dist, dist+n+k, (long long)(1e18));
  priority_queue<pair<long long, int>> pq;
  dist[0] = 0;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    int v = pq.top().second;
    long long w = -pq.top().first;
    pq.pop();
    if (dist[v] != w) continue;
    for (auto it : g[v]) {
      long long cur = w + it.second;
      int u = it.first;
      if (dist[u] > cur) {
        dist[u] = cur;
        pq.emplace(-cur, u);
      }
    }
  }
  printf("%lld\n", dist[n-1]);
  return 0;
}
