#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> e[N];
vector<int> ev[N];
int p[N], cyc[N], ada[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v, int t) {
  if ((u = find(u)) == (v = find(v))) {
    for (int x : e[u])
      cyc[x] = t;
    e[u].clear();
    ada[u] = 1;
    return false;
  }
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  ada[v] |= ada[u];
  p[u] = v;
  for (int x : e[u])
    e[v].push_back(x);
  for (int x : ev[u])
    ev[v].push_back(x);
  ev[v].push_back(t);
  if (ada[v]) {
    for (int x : e[v])
      cyc[x] = t;
    e[v].clear();
  }
  return true;
}
set<pair<int, int> > edge;
pair<int, int> vp[N];

int main() {
  int n, m, op, q;
  scanf("%d %d %d %d", &n, &m, &op, &q);
  fill(p, p+n, -1);
  fill(cyc, cyc+n, -1);
  for (int i = 0; i < n; ++i)
    e[i].push_back(i);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    if (u > v) swap(u, v);
    edge.insert(make_pair(u, v));
  }
  for (int i = 0; i < op; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    if (u > v) swap(u, v);
    vp[i] = {u, v};
    edge.erase(vp[i]);
  }
  for (auto it : edge)
    merge(it.first, it.second, op);
  for (int i = op-1; i >= 0; --i) {
    merge(vp[i].first, vp[i].second, i);
  }
  for (int i = 0; i < n; ++i) if (p[i] < 0) {
    sort(ev[i].begin(), ev[i].end());
  }
  for (int i = 0; i < q; ++i) {
    int u, t;
    scanf("%d %d", &u, &t);
    --u;
    if (t == 1)
      printf("%d\n", cyc[u]);
    else {
      int z;
      scanf("%d", &z);
      u = find(u);
      int ans = op+1;
      --z;
      if (z == 0)
        ans = 0;
      else if (z <= ev[u].size()) {
        ans = ev[u][z-1]+1;
      }
      printf("%d\n", ans);
    } 
  }
  return 0; 
}