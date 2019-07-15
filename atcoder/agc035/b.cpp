#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

set<int> e[N], g[N];
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

vector<tuple<int, int, int> > ans;

int main() {
  memset(p, -1, sizeof p);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (merge(u, v)) {
      g[u].insert(v);
      g[v].insert(u);
    }
    else {
      e[u].insert(v);
      e[v].insert(u);
    }
  }
  if (m & 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    while (e[i].size() >= 2) {
      auto it = e[i].begin(), it2 = it;
      ++it2;
      ans.emplace_back(*it, i, *it2);
      e[*it].erase(i);
      e[i].erase(it);
      e[*it2].erase(i);
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
    int par = *it;
    g[v].erase(it);
    g[par].erase(v);
    pq.emplace(-(int)g[par].size(), par);
    if (e[v].size() > 0) {
      assert(e[v].size() == 1);
      it = e[v].begin();
      ans.emplace_back(*it, v, par);
      e[*it].erase(v);
      e[v].erase(it);
    }
    else {
      if (e[par].size() > 0) {
        assert(e[par].size() == 1);
        it = e[par].begin();
        ans.emplace_back(*it, par, v);
        e[*it].erase(par);
        e[par].erase(it);
      }
      else {
        e[par].insert(v);
        e[v].insert(par);
      }
    }
  }
  for (auto boom : ans) {
    int u, v, w;
    tie(u,v,w) = boom;
    printf("%d %d\n%d %d\n", v, u, v, w);
  }
  return 0;
}