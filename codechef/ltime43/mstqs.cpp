#include <bits/stdc++.h>

using namespace std;

const int N = 2017;
int g[N][N];

struct dsu {
  int p[N];
  dsu() {
    memset(p, -1, sizeof p);
  }
  void reset() {
    memset(p, -1, sizeof p);
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
      return false;
    if (p[u] < p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

bool cmp(pair< int, int > e, pair< int, int > f) {
  return g[e.first][e.second] < g[f.first][f.second];
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  memset(g, -1, sizeof g);
  vector< pair<int, int > > edges, mst;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    edges.push_back({u, v});
    g[u][v] = w;
    g[v][u] = w;
  }
  sort(edges.begin(), edges.end(), cmp);
  dsu now;
  for (int i = 0; i < m; i++) {
    if (now.merge(edges[i].first, edges[i].second)) {
      mst.push_back(edges[i]);
    }
  }
  now.reset();
  set< pair< int, int > > st;
  while (q--) {
    int t, u, v;
    scanf("%d", &t);
    if (t == 3) {
      dsu tmp = now;
      long long ans = 0;
      for (int i = 0; i < mst.size(); i++) {
        if (tmp.merge(mst[i].first, mst[i].second))
          ans += g[mst[i].first][mst[i].second];
      }
      printf("%lld\n", ans);
      continue;
    }
    scanf("%d %d", &u, &v);
    u--; v--;
    if (t == 1) {
      now.merge(u, v);
      st.insert(make_pair(u, v));
    }
    else {
      st.erase(make_pair(u, v));
      now.reset();
      for (auto it : st)
        now.merge(it.first, it.second);
    }
  }
  return 0;
}