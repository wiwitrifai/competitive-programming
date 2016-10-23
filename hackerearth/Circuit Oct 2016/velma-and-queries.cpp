#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector< int > adj[N];
vector< pair<int, int > > que[N];
int n, q;
int a[N];
long long ans[N], cnt[N], sz[N], lv[N];

void getsz(int u, int p = -1) {
  sz[u] = 1;
  for (int v : adj[u]) if (v != p) {
    lv[v] = lv[u] + 1;
    getsz(v, u);
    sz[u] += sz[v];
  }
}

void process(int v, int p, int add) {
  cnt[lv[v]] += add * a[v];
  for (int u : adj[v]) if (u != p)
    process(u, v, add);
}

void dfs(int v, int p = -1) {
  int bg = -1;
  for (int u : adj[v]) if (u != p) {
    if (bg == -1 || sz[u] > sz[bg])
      bg = u;
  }
  for (int u : adj[v]) if (u != bg && u != p) {
    dfs(u, v);
    process(u, v, -1);
  }
  if (bg != -1) {
    dfs(bg, v);
    for (int u : adj[v]) if (u != p && u != bg) {
      process(u, v, +1);
    }
  }
  cnt[lv[v]] += a[v];
  for (auto it : que[v]) {
    ans[it.first] = cnt[it.second];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      que[i].clear();
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[v].push_back(u);
      adj[u].push_back(v);
    }
    for (int i = 0; i < q; i++) {
      int u, l;
      scanf("%d %d", &u, &l);
      u--;
      que[u].push_back({i, l});
    }
    lv[0] = 1;
    getsz(0);
    dfs(0);
    for (int i = 0; i < q; i++) {
      printf("%lld\n", ans[i]);
    }
  }
  return 0;
}