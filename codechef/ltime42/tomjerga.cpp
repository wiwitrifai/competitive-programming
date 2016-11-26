#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LOG = 20;

vector< int > adj[N];
int par[LOG][N], lv[N];
int far[N];

void dfs(int v = 0) {
  for (int i = 0; i + 1 < LOG; i++) {
    par[i+1][v] = par[i][par[i][v]];
  }
  far[v] = 0;
  for (int u : adj[v]) if (u != par[0][v]) {
    par[0][u] = v;
    lv[u] = lv[v] + 1;
    dfs(u);
    far[v] = max(far[v], far[u] + 1);
  }
}

int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = LOG-1; i >= 0; i--) if (diff & (1<<i))
    v = par[i][v];
  if (u == v)
    return u;
  for (int i = LOG-1; i >= 0; i--) if (par[i][u] != par[i][v])
    u = par[i][u], v = par[i][v];
  return par[0][u];
}

vector< pair<int, int> > que[N];
int ans[N], val[N];
vector< int > cfar[N];
void dfs2(int v, int up = 0) {
  cfar[v].clear();
  int tmp = 0;
  sort(adj[v].begin(), adj[v].end());
  for (int i = 0; i < adj[v].size(); i++) {
    cfar[v].push_back(tmp);
    if (adj[v][i] == par[0][v])
      tmp = max(tmp, up);
    else
      tmp = max(tmp, far[adj[v][i]]+1);
  }
  tmp = 0;
  sort(que[v].begin(), que[v].end());
  int id = (int)que[v].size() - 1;
  for (int i = (int)adj[v].size()-1; i >= 0; i--) {
    int u = adj[v][i];
    while (id >= 0 && que[v][id].first == u) {
      ans[que[v][id].second] += max(tmp, cfar[v][i]);
      id--;
    }
    // cerr << v << " " << u << " " << max(tmp, cfar[v][i]) << endl;
    if (u != par[0][v])
      dfs2(u, max(tmp, cfar[v][i])+1);
    if (u == par[0][v])
      tmp = max(tmp, up);
    else
      tmp = max(tmp, far[u]+1);
  }
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      que[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    par[0][0] = 0; 
    dfs();
    for (int i = 0; i < q; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      x--; y--;
      if (x == y) {
        ans[i] = 0;
        continue;
      }
      int w = lca(x, y);
      int len = lv[x] + lv[y] - 2 * lv[w];
      int mid = (len-1)/2;
      if (lv[y] > mid + lv[w]) {
        for (int j = 0; j < LOG; j++) if (mid & (1<<j))
          y = par[j][y];
        que[y].push_back({par[0][y], i});
        ans[i] = lv[y] + lv[x] - 2 * lv[w];
        // cerr << y << " hehe " << ans[i] << endl;
      }
      else {
        mid = len - mid - 1;
        // assert(lv[x] > mid + lv[w]);
        for (int j = 0; j < LOG; j++) if (mid & (1<<j))
          x = par[j][x];
        que[par[0][x]].push_back({x, i});
        ans[i] = mid+1;
      }
    }
    dfs2(0);
    for (int i = 0; i < q; i++)
      printf("%d\n", ans[i]);
  }
  return 0;
}