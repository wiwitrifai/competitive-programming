#include <bits/stdc++.h>

using namespace std;

vector<int> x;
vector<int> a, b;

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  x.resize(n);
  a.resize(m);
  b.resize(m);
  x[0] = 0;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a[i], &b[i]);
    --a[i];
    --b[i];
  }
  vector<int> vabs, vrel;
  for (int i = 0; i < n; ++i) {
    if (x[i] >= 0) {
      vabs.push_back(i);
    } else {
      vrel.push_back(i);
    }
  }
  sort(vabs.begin(), vabs.end(), [&](int l, int r) {
    return x[l] < x[r];
  });
  sort(vrel.begin(), vrel.end(), [&](int l, int r) {
    return -x[l] < -x[r];
  });
  vector<int> topo, pos(n);
  int iabs = 0;
  for (int v : vrel) {
    assert(-x[v] > 0);
    while (iabs < (int)vabs.size() && (int)topo.size() < -x[v]) {
      topo.push_back(vabs[iabs++]);
    }
    topo.push_back(v);
  }
  while (iabs < (int)vabs.size())
    topo.push_back(vabs[iabs++]);
  assert((int)topo.size() == n);
  for (int i = 0; i < (int)topo.size(); ++i) {
    pos[topo[i]] = i;
  }
  assert(pos[0] == 0);
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    if (pos[a[i]] > pos[b[i]])
      swap(a[i], b[i]);
    int u = a[i], v = b[i];
    if (x[u] == x[v]) {
      g[u].emplace_back(v, 0);
      g[v].emplace_back(u, 0);
    } else {
      int cost = 1;
      if (x[u] < 0 && x[v] > 0)
        cost = 0;
      g[u].emplace_back(v, cost);
    }
  }

  for (int i = 0; i + 1 < (int)topo.size(); ++i) {
    int u = topo[i], v = topo[i+1];
    if (x[u] == x[v]) {
      g[u].emplace_back(v, 0);
      g[v].emplace_back(u, 0);
    } else {
      int cost = 1;
      if (x[u] < 0 && x[v] > 0)
        cost = 0;
      g[u].emplace_back(v, cost);
    }
  }

  vector<int> lat = x;
  while (1) {
    bool done = true;
    for (int v : topo) {
      for (auto e : g[v]) {
        int u = e.first, w = e.second;
        if (lat[u] < lat[v]+w) {
          lat[u] = lat[v] + w;
          done = false;
        }
      }
    }
    if (done)
      break;
  }
  for (int i = 0; i < m; ++i) {
    assert(lat[b[i]] >= lat[a[i]]);
    int ans = max(1, abs(lat[b[i]] - lat[a[i]]));
    printf("%d%c", ans, i+1 == m ? '\n' : ' ');
  }
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
