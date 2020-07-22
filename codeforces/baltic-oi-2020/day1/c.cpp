#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p, col;
  vector<pair<int*, int>> logs;
  void assign(int * var, int val) {
    logs.emplace_back(var, *var);
    *var = val;
  }
  Dsu(int size) {
    p.assign(size, -1);
    col.assign(size, 0);
  }
  int find(int x) {
    return p[x] < 0 ? x : find(p[x]);
  }
  int find_col(int x) {
    return p[x] < 0 ? col[x] : col[x] ^ find_col(p[x]);
  }
  bool merge(int u, int v) {
    int tu = u, tv = v;
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (-p[u] > -p[v])
      swap(u, v);
    assign(&p[v], p[v] + p[u]);
    assign(&p[u], v);
    if (find_col(tu) == find_col(tv)) {
      assign(&col[u], col[u]^1);
    }
    return true;
  }
  void reset(int version) {
    while ((int)logs.size() > version) {
      *logs.back().first = logs.back().second;
      logs.pop_back();
    }
  }
};

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edges[i] = {u, v};
  }
  vector<pair<int, int>> queries(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    queries[i] = {l, r};
  }
  vector<int> limit(m, -1);

  Dsu dsu(n);

  function<void(int, int, int, int)> dnc = [&](int l, int r, int low, int hig) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    int version = dsu.logs.size();
    for (int i = l; i < mid; ++i) {
      dsu.merge(edges[i].first, edges[i].second);
      if (dsu.find_col(edges[i].first) == dsu.find_col(edges[i].second)) {
        limit[mid] = low;
      }
    }
    if (limit[mid] != -1) {
      for (int i = mid+1; i < r; ++i) {
        limit[i] = low;
      }
      dsu.reset(version);
      dnc(l, mid, low, hig);
      return;
    }
    int upper = min(hig, m - mid);
    int version2 = dsu.logs.size();
    limit[mid] = upper;
    for (int i = low; i < upper; ++i) {
      int u = edges[m-1-i].first, v = edges[m-1-i].second;
      dsu.merge(u, v);
      if (dsu.find_col(u) == dsu.find_col(v)) {
        limit[mid] = i + 1;
        break;
      }
    }
    dsu.reset(version2);
    if (mid + 1 < r) {
      dsu.merge(edges[mid].first, edges[mid].second);
      if (dsu.find_col(edges[mid].first) == dsu.find_col(edges[mid].second)) {
        for (int i = mid+1; i < r; ++i)
          limit[i] = low;
      } else {
        dnc(mid+1, r, low, limit[mid]);
      }
    }
    dsu.reset(version);
    bool ok = true;
    for (int i = low; i < limit[mid]; ++i) {
      int u = edges[m-1-i].first, v = edges[m-1-i].second;
      dsu.merge(u, v);
      if (dsu.find_col(u) == dsu.find_col(v)) {
        ok = false;
      }
    }
    if (ok)
      dnc(l, mid, limit[mid], hig);
    else
      for (int j = l; j < mid; ++j)
        limit[j] = limit[mid];
  };
  dnc(0, m, 0, m);
  for (int i = 0; i+1 < m; ++i)
    limit[i+1] = min(limit[i], limit[i+1]);
  for (int i = 0; i < q; ++i) {
    auto it = queries[i];
    int l = it.first, r = it.second + 1;
    puts(m-r >= limit[l] ? "YES" : "NO");
  }
  return 0;
}
