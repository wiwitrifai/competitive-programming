#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, S = sqrt(N);

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

set<pair<int, int>> edges;
int t[N], a[N], b[N];
set<int> g[N];
bool vis[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", t+i, a+i, b+i);
    --a[i], --b[i];
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
  }
  for (int i = 0; i < m; i += S) {
    int til = min(m, i+S);
    set<pair<int, int>> invalid;
    for (int j = i; j < til; ++j) {
      if (t[j] == 2) continue;
      int u = a[j], v = b[j];
      invalid.insert(make_pair(u, v));
      ++u, ++v;
      if (u >= n)
        u -= n;
      if (v >= n)
        v -= n;
      if (u > v) swap(u, v);
      invalid.insert(make_pair(u, v));
    }
    fill(p, p+n, -1);
    for (auto e : edges) {
      if (invalid.count(e)) continue;
      merge(e.first, e.second);
    }
    set<int> nodes;
    for (auto e : invalid) {
      nodes.insert(find(e.first));
      nodes.insert(find(e.second));
    }
    for (auto e : invalid) {
      if (edges.count(e)) {
        int u = find(e.first), v = find(e.second);
        g[u].insert(v);
        g[v].insert(u);
      }
    }
    for (int j = i; j < til; ++j) {
      int u = a[j], v = b[j];
      if (ans) {
        ++u, ++v;
        if (u >= n)
          u -= n;
        if (v >= n)
          v -= n;
        if (u > v) swap(u, v);
      }
      if (t[j] == 1) {
        pair<int, int> cur = {u, v};
        if (edges.count(cur)) {
          edges.erase(cur);
          bool del = 1;
          u = find(u);
          v = find(v);
          for (auto e : invalid) {
            if (!edges.count(e)) continue;
            if ((u == find(e.first) && v == find(e.second)) || (v == find(e.first) && u == find(e.second))) {
              del = 0;
              break;
            }
          }
          if (del) {
            g[u].erase(v);
            g[v].erase(u);
          }
        }
        else {
          edges.insert(cur);
          u = find(u);
          v = find(v);
          g[v].insert(u);
          g[u].insert(v);
        }
      }
      else {
        u = find(u);
        v = find(v);
        queue<int> que;
        que.push(u);
        vis[u] = 1;
        vector<int> visited;
        visited.push_back(u);
        while (!que.empty()) {
          int now = que.front(); que.pop();
          if (now == v) break;
          for (int nx : g[now]) {
            if (vis[nx]) continue;
            vis[nx] = 1;
            que.push(nx);
            visited.push_back(nx);
          }
        }
        ans = vis[v];
        printf("%d", ans);
        for (int x : visited)
          vis[x] = 0;
      }
    }
    for (int v : nodes) {
      g[v].clear();
    }
  }
  printf("\n");
  return 0;
}
