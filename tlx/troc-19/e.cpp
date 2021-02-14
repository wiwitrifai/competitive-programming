#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  int cnt = 0;
  Dsu(int _n) : p(_n, -1), cnt(_n) {}
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    --cnt;
    return true;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n), c(n), d(n);
  vector<long long> area(n);
  vector<tuple<int, int, int, int>> xevents, yevents;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    int dx = c[i] - a[i], dy = d[i] - b[i];
    area[i] = 1LL * dx * dy;
    xevents.emplace_back(a[i], b[i], d[i], i);
    xevents.emplace_back(c[i], b[i], d[i], i);
    yevents.emplace_back(b[i], a[i], c[i], i);
    yevents.emplace_back(d[i], a[i], c[i], i);
  }
  vector<tuple<long long, int, int>> edges;
  auto process = [&](vector<tuple<int, int, int, int>> & events) {
    sort(events.begin(), events.end());
    tuple<int, int, int, int> last = events[0];
    for (int i = 1; i < (int)events.size(); ++i) {
      auto & e = events[i];
      if (get<0>(e) != get<0>(last)) {
        last = e;
        continue;
      }
      if (get<1>(e) < get<2>(last) && get<1>(last) < get<2>(e)) {
        int u = get<3>(e), v = get<3>(last);
        edges.emplace_back(abs(area[u] - area[v]), u, v);
      }
      if (get<2>(e) > get<2>(last))
        last = e;
    }
  };
  process(xevents);
  process(yevents);
  sort(edges.begin(), edges.end());
  long long ans = 0;
  Dsu dsu(n);
  for (auto & e : edges) {
    int u, v;
    long long cost;
    tie(cost, u, v) = e;
    if (dsu.cnt <= 2) break;
    if (dsu.merge(u, v)) {
      ans += cost;
    }
  }
  if (dsu.cnt != 2) {
    ans = -1;
  }
  printf("%lld\n", ans);
  return 0;
}
