#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int l[N], r[N];

vector<int> g[N];
int din[N];
vector<int> add[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", l+i, r+i);
    --l[i];
  }
  vector<int> topo;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    ++din[v];
  }
  for (int i = 0; i < n; ++i)
    if (din[i] == 0)
      topo.push_back(i);
  for (int i = 0; i < (int)topo.size(); ++i) {
    int v = topo[i];
    for (int u : g[v]) {
      --din[u];
      if (din[u] == 0)
        topo.push_back(u);
    }
  }
  if ((int)topo.size() != n) {
    puts("-1");
    return 0;
  }
  for (int v : topo) {
    for (int u : g[v]) {
      l[u] = max(l[u], l[v]+1);
    }
  }
  for (int i = n-1; i >= 0; --i) {
    int v = topo[i];
    for (int u : g[v]) {
      r[v] = min(r[v], r[u]-1);
    }
    if (l[v] >= r[v]) {
      puts("-1");
      return 0;
    }
  }
  memset(din, 0, sizeof din);
  for (int i = 0; i < n; ++i) {
    add[l[i]].push_back(i);
  }
  memset(din, 0, sizeof din);
  for (int v = 0; v < n; ++v)
    for (int u : g[v])
      ++din[u];
  vector<int> ans(n);
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; ++i) {
    for (int v : add[i])
      if (din[v] == 0) {
        pq.emplace(-r[v], v);
      }
    if (pq.empty()) {
      puts("-1");
      return 0;
    }
    int v = pq.top().second;
    if (r[v] <= i) {
      puts("-1");
      return 0;
    }
    ans[i] = v;
    pq.pop();
    for (int u : g[v]) {
      --din[u];
      if (l[u] <= i && din[u] == 0)
        pq.emplace(-r[u], u);
    }
  }
  for (int v : ans)
    printf("%d\n", v+1);
  return 0;
}
