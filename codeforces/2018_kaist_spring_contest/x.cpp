#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7, N = 1e6 + 6;

int awal[N], akhir[N];
int x[N], y[N], w[N];
vector<pair<int, int>> fir[N], sec[N];
int node[5];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", x+i, y+i, w+i);
    --x[i], --y[i];
  }
  if (k > n-1 || k > m || k == 0) {
    puts("-1");
    return 0;
  }
  fill(akhir, akhir+n, inf);
  fill(awal, awal+n, inf); 
  for (int i = 0; i < m; ++i) {
    if (x[i] == y[i]) continue;
    if (x[i] > y[i])
      swap(x[i], y[i]);
    if (x[i] == 0)
      awal[y[i]] = min(awal[y[i]], w[i]);
    if (y[i] == n-1)
      akhir[x[i]] = min(akhir[x[i]], w[i]);
  }
  if (k == 1) {
    int ans = awal[n-1];
    if (ans >= inf)
      ans = -1;
    printf("%d\n", ans);
    return 0;
  }
  if (k == 2) {
    int ans = inf;
    for (int i = 2; i < n-1; ++i) {
      ans = min(ans, awal[i] + akhir[i]);
    }
    if (ans >= inf)
      ans = -1;
    printf("%d\n", ans);
    return 0;
  }
  if (k == 3) {
    int ans = inf;
    for (int i = 0; i < m; ++i) {
      if (x[i] == y[i]) continue;
      if (x[i] == 0 || y[i] == n-1) continue;
      if (awal[x[i]] != inf && akhir[y[i]] != inf) {
        ans = min(ans, awal[x[i]] + akhir[y[i]] + w[i]);
      }
      if (awal[y[i]] != inf && akhir[x[i]] != inf) {
        ans = min(ans, awal[y[i]] + akhir[x[i]] + w[i]);
      }
    }
    if (ans >= inf)
      ans = -1;
    printf("%d\n", ans);
    return 0;
  }
  vector<pair<pair<int, int>, int>> edges;
  for (int i = 0; i < m; ++i) {
    if (x[i] == y[i]) continue;
    if (x[i] == 0 || y[i] == n-1) continue;
    edges.emplace_back(make_pair(x[i], y[i]), w[i]);
  }
  sort(edges.begin(), edges.end());
  vector<pair<pair<int, int>, int>> smallest;
  pair<int, int> last = {-1, -1};
  for (auto it : edges) {
    if (it.first == last) continue;
    smallest.push_back(it);
    last = it.first;
  }
  for (auto it : smallest) {
    pair<int, int> e = it.first;
    int b = it.second;
    if (awal[e.first] != inf) {
      fir[e.second].emplace_back(b + awal[e.first], e.first);
    }
    if (awal[e.second] != inf) {
      fir[e.first].emplace_back(b + awal[e.second], e.second);
    }
    if (akhir[e.first] != inf) {
      sec[e.second].emplace_back(b + akhir[e.first], e.first);
    }
    if (akhir[e.second] != inf) {
      sec[e.first].emplace_back(b + akhir[e.second], e.second);
    }
  }
  for (int i = 0; i < n; ++i) {
    sort(fir[i].begin(), fir[i].end());
    sort(sec[i].begin(), sec[i].end());
    if (fir[i].size() > 3)
      fir[i].resize(3);
    if (sec[i].size() > 3)
      sec[i].resize(3);
  }
  if (k == 4) {
    int ans = inf;
    for (int v = 1; v < n-1; ++v) {
      if (fir[v].empty() || sec[v].empty()) continue;
      if (fir[v][0].second != sec[v][0].second) {
        ans = min(ans, fir[v][0].first + sec[v][0].first);
      }
      else {
        if (fir[v].size() > 1) {
          ans = min(ans, fir[v][1].first + sec[v][0].first);
        }
        if (sec[v].size() > 1) {
          ans = min(ans, fir[v][0].first + sec[v][1].first);
        }
      }
    }
    if (ans >= inf)
      ans = -1;
    printf("%d\n", ans);
    return 0;
  }
  assert(k == 5);
  int ans = inf;
  for (auto it : smallest) {
    int u = it.first.first, v = it.first.second, b = it.second;
    for (auto e1 : fir[u]) {
      for (auto e2 : sec[v]) {
        node[0] = u;
        node[1] = v;
        node[2] = e1.second;
        node[3] = e2.second;
        sort(node, node+4);
        bool ok = 1;
        for (int i = 0; i < 3; ++i)
          if (node[i] == node[i+1])
            ok = 0;
        if (ok) {
          ans = min(ans, e1.first + b + e2.first);
        }
      }
    }
    for (auto e1 : fir[v]) {
      for (auto e2 : sec[u]) {
        node[0] = u;
        node[1] = v;
        node[2] = e1.second;
        node[3] = e2.second;
        sort(node, node+4);
        bool ok = 1;
        for (int i = 0; i < 3; ++i)
          if (node[i] == node[i+1])
            ok = 0;
        if (ok) {
          ans = min(ans, e1.first + b + e2.first);
        }
      }
    }
  }
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}
