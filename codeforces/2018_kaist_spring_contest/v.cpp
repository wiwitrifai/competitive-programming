#include <bits/stdc++.h>

using namespace std;

const int N = 250123;
const long long inf = 1LL << 61;

vector<pair<int, int>> g[N];
pair<long long, int> dist[N];
int a[N];
long long ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    w *= 2;
    g[u].emplace_back(v, w);
    if (u != v)
      g[v].emplace_back(u, w);
  }
  fill(dist, dist+n, make_pair(inf, n+1));
  int k;
  scanf("%d", &k);
  priority_queue<pair<pair<long long, int>, int>> pq;
  for (int i = 0; i < k; ++i) {
    scanf("%d", a+i);
    --a[i];
    dist[a[i]] = make_pair(0, a[i]);
    pq.emplace(make_pair(0LL, -a[i]), a[i]);
  }
  while (!pq.empty()) {
    pair<long long, int> cur = pq.top().first;
    int v = pq.top().second;
    cur.first *= -1;
    cur.second *= -1;
    pq.pop();
    if (dist[v] != cur) continue;
    for (auto e : g[v]) {
      int u = e.first, w = e.second;
      pair<long long, int> nxt = make_pair(cur.first + w, cur.second);
      if (nxt < dist[u]) {
        dist[u] = nxt;
        nxt.first *= -1;
        nxt.second *= -1;
        pq.emplace(nxt, u);
      }
    }
  }
  for (int v = 0; v < n; ++v) {
    for (auto e : g[v]) {
      int u = e.first, w = e.second;
      if (u > v) continue;
      if (dist[u].second == dist[v].second) {
        ans[dist[u].second] += w;
      }
      else {
        long long mid = (dist[u].first + dist[v].first + w);
        assert((mid & 1) == 0);
        mid /= 2;
        mid = max(dist[v].first, min(mid, dist[v].first+w)) - dist[v].first;
        ans[dist[v].second] += mid;
        ans[dist[u].second] += w - mid;
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    int v = a[i];
    printf("%lld.%d\n", ans[v]/2, (ans[v]&1) ? 5 : 0);
  }
  return 0;
}
