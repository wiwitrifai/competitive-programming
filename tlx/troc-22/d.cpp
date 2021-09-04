#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

long long dist[N];
vector<pair<int, int>> g[N];
int p[N], a[N];
int n, m, k;

int dijkstra(int limit) {
  fill(dist, dist + n, inf);
  priority_queue<pair<long long, int>> pq;
  for (int i = 0; i <= limit; ++i) {
    dist[i] = 0;
    pq.emplace(0, i);
  }
  while (!pq.empty()) {
    long long w;
    int v;
    tie(w, v) = pq.top();
    w = -w;
    pq.pop();
    if (w != dist[v]) continue;
    for (auto & e : g[v]) {
      long long cur = w + e.second;
      int u = e.first;
      if (cur < dist[u]) {
        dist[u] = cur;
        pq.emplace(-cur, u);
      }
    }
  }
  for (int i = k-1; i >= 0; --i) {
    if (a[i] < dist[p[i]])
      return i;
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d %d", p+i, a+i);
    --p[i];
  }
  int low = 0, hig = n-1;
  while (low < hig) {
    int mid = (low + hig) >> 1;
    int res = dijkstra(mid);
    if (res == -1) {
      hig = mid;
    } else {
      low = mid + 1;
    }
  }
  int ans = dijkstra(low-1);
  printf("%d\n", ans + 1);
  return 0;
}
