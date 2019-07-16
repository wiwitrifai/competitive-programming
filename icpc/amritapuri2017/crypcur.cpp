#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
set<int> dag[N];
int ng, grup[N], cntr, din[N];
tuple<int, int, int > edge[N];
int vis[N], num[N], low[N];

stack<int> S;
void dfs(int v) {
  num[v] = low[v] = cntr++;
  vis[v] = 1;
  S.push(v);
  for (int u : g[v]) {
    if (num[u] == -1)
      dfs(u);
    if (vis[u])
      low[v] = min(low[v], low[u]);
  }
  if (num[v] == low[v]) {
    while (!S.empty()) {
      int u = S.top(); S.pop();
      grup[u] = ng;
      vis[u] = 0;
      if (u == v) break;
    }
    ++ng;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      --u, --v;
      edge[i] = {w, u, v};
    }
    sort(edge, edge+m);
    int le = 0, ri = m+1;
    while (le < ri) {
      int mid = (le + ri) >> 1;
      for (int i = 0; i < n; ++i) {
        g[i].clear();
        num[i] = -1;
        vis[i] = 0;
      }
      for (int i = 0; i < mid; ++i)
        g[get<1>(edge[i])].emplace_back(get<2>(edge[i]));
      ng = cntr = 0;
      for (int i = 0; i < n; ++i) if (num[i] == -1) {
        dfs(i);
      }
      for (int i = 0; i < ng; ++i)
        dag[i].clear(), din[i] = 0;
      for (int v = 0; v < n; ++v) {
        for (int u : g[v]) if (grup[u] != grup[v]) {
          if (!dag[grup[v]].count(grup[u])) {
            dag[grup[v]].insert(grup[u]);
            ++din[grup[u]];
          }
        }
      }
      stack<int> st;
      vector<int> topo;
      for (int i = 0; i < ng; ++i) {
        if (din[i] == 0)
          st.push(i);
      }
      while (!st.empty()) {
        int v = st.top(); st.pop();
        topo.push_back(v);
        for (int u : dag[v]) {
          --din[u];
          if (din[u] == 0)
            st.push(u);
        }
      }
      bool ok = topo.size() == ng;
      for (int i = 0; i+1 < ng; ++i)
        ok &= dag[topo[i]].count(topo[i+1]);
      if (ok)
        ri = mid;
      else
        le = mid+1;
    }
    if (le > m)
      puts("Impossible");
    else
      printf("%d\n", le ? get<0>(edge[le-1]) : 0);
  }
  return 0;
}