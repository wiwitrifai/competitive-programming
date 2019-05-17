#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct DSU {
  set<int> st[N];
  int p[N];
  DSU() {
    memset(p, -1, sizeof p);
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  void merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
      return;
    if (st[u].size() < st[v].size())
      swap(u, v);
    for (int x : st[v])
      st[u].insert(x);
    p[v] = u;
  }
  void add(int u, int e) {
    st[find(u)].insert(e);
  }
  bool get(int u, int e) {
    return st[find(u)].count(e);
  }
} elem, neigh;
map<int, int> to[N];

inline void merge(int u, int v) {
  elem.merge(u, v);
  neigh.merge(u, v);
}

inline void add_edge(int u, int v, int w) {
  neigh.add(u, v);
  neigh.add(v, u);
  auto it = to[u].find(w);
  if (it != to[u].end()) {
    merge(it->second, v);
  }
  else
    to[u][w] = v;
  it = to[v].find(w);
  if (it != to[v].end()) {
    merge(it->second, u);
  }
  else
    to[v][w] = u;
}

int main() {
  int n, m, c, q;
  scanf("%d %d %d %d", &n, &m, &c, &q);
  for (int i = 1; i <= n; ++i)
    elem.add(i, i);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    add_edge(u, v, w);
  }
  for (int i = 0; i < q; ++i) {
    char s[3];
    int x, y, z;
    scanf("%s %d %d", s, &x, &y);
    if (s[0] == '+') {
      scanf("%d", &z);
      add_edge(x, y, z);
    }
    else {
      bool res = elem.get(x, y) || neigh.get(x, y);
      puts(res ? "Yes" : "No");
    }
  }
  return 0;
}
