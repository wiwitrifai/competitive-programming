#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, xs, ys, xf, yf;
  scanf("%d %d %d %d %d", &n, &xs, &ys, &xf, &yf);
  vector<pair<int, int>> xranges, yranges;
  xranges.emplace_back(xs, xs);
  xranges.emplace_back(xf, xf);
  yranges.emplace_back(ys, ys);
  yranges.emplace_back(yf, yf);
  vector<int> xp(n), yp(n), rp(n), cp(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d", &xp[i], &yp[i], &rp[i], &cp[i]);
    xranges.emplace_back(xp[i]-rp[i], xp[i]+rp[i]);
    yranges.emplace_back(yp[i]-rp[i], yp[i]+rp[i]);
  }
  auto combine = [&](vector<pair<int, int>> & ranges) {
    sort(ranges.begin(), ranges.end());
    vector<pair<int, int>> result;
    for (int i = 0; i < (int)ranges.size();) {
      int from = ranges[i].first, til = ranges[i].second;
      while (i < (int)ranges.size() && ranges[i].first <= til) {
        til = max(til, ranges[i].second);
        ++i;
      }
      result.emplace_back(from, til);
    }
    return result;
  };
  xranges = combine(xranges);
  yranges = combine(yranges);
  vector<vector<pair<int, int>>> g(xranges.size() + yranges.size());
  auto find_range = [&](vector<pair<int, int>> & ranges, int x) {
    int pos = lower_bound(ranges.begin(), ranges.end(), make_pair(x+1, -int(1e9 + 7))) - ranges.begin() - 1;
    assert(pos >= 0 && ranges[pos].first <= x && x <= ranges[pos].second);
    return pos;
  };
  for (int i = 0; i < n; ++i) {
    int u = find_range(xranges, xp[i]), v = find_range(yranges, yp[i]) + xranges.size();
    g[u].emplace_back(v, cp[i]);
    g[v].emplace_back(u, cp[i]);
  }
  int s = find_range(yranges, ys) + xranges.size(), fx = find_range(xranges, xf), fy = find_range(yranges, yf) + xranges.size();
  const long long inf = 1e18;
  vector<long long> dist(xranges.size() + yranges.size(), inf);
  priority_queue<pair<long long, int>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    long long cur = -pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (cur != dist[v]) continue;
    for (auto & e : g[v]) {
      int u = e.first;
      if (dist[u] > dist[v] + e.second) {
        dist[u] = dist[v] + e.second;
        pq.emplace(-dist[u], u);
      }
    }
  }
  long long ans = min(dist[fx], dist[fy]);
  if (ans >= inf)
    ans = -1;
  printf("%lld\n", ans);
  return 0;
}
