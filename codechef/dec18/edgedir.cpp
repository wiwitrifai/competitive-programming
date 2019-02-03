#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

set<int> e[N], g[N];

int ans[N];
int a[N], b[N];

int p[N];
int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(p, -1, sizeof p);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      e[i].clear();
    }
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      a[i] = u;
      b[i] = v;
      if (merge(u, v)) {
        g[u].insert(i);
        g[v].insert(i);
      }
      else {
        e[u].insert(i);
        e[v].insert(i);
      }
    }
    for (int i = 1; i <= n; ++i) {
      while (e[i].size() >= 2) {
        auto it = e[i].begin(), it2 = it;
        ++it2;
        if (i == a[*it]) {
          ans[*it] = 1;
          e[b[*it]].erase(*it);
        }
        else
          e[a[*it]].erase(*it);
        e[i].erase(it);
        if (i == a[*it2]) {
          ans[*it2] = 1;
          e[b[*it2]].erase(*it2);
        }
        else
          e[a[*it2]].erase(*it2);
        e[i].erase(it2);
      }
    }
    priority_queue<pair<int, int> > pq;
    for (int i = 1; i <= n; ++i) {
      pq.emplace(-(int)g[i].size(), i);
    }
    while (!pq.empty()) {
      int v = pq.top().second, cnt = -pq.top().first; pq.pop();
      if (cnt != g[v].size()) continue;
      if (g[v].empty()) continue;
      assert(g[v].size() == 1);
      auto it = g[v].begin();
      int id = *it;
      int par = a[id]^b[id]^v;
      g[v].erase(it);
      g[par].erase(id);
      pq.emplace(-(int)g[par].size(), par);
      if (e[v].size() > 0) {
        assert(e[v].size() == 1);
        it = e[v].begin();
        if (a[id] == v)
          ans[id] = 1;
        if (a[*it] == v) {
          ans[*it] = 1;
          e[b[*it]].erase(*it);
        }
        else
          e[a[*it]].erase(*it);
        e[v].erase(it);
      }
      else {
        if (e[par].size() > 0) {
          assert(e[par].size() == 1);
          it = e[par].begin();
          if (a[id] == par)
            ans[id] = 1;
          if (a[*it] == par) {
            ans[*it] = 1;
            e[b[*it]].erase(*it);
          }
          else
            e[a[*it]].erase(*it);
          e[par].erase(it);
        }
        else {
          e[par].insert(id);
          e[v].insert(id);
        }
      }
    }
    bool ok = 1;
    for (int i = 1; i <= n; ++i)
      if (e[i].size() + g[i].size() > 0)
        ok = 0;
    if (ok) {
      for (int i = 0; i < m; ++i)
        printf("%d%c", ans[i], i == m-1 ? '\n' : ' ');
    }
    else
      puts("-1");
    }
  return 0;
}