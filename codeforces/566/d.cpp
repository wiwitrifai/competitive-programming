#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int par[N], lv[N];

void dfs(int v) {
  lv[v] = par[v] == -1 ? 0 : lv[par[v]] + 1;
  for (int u : g[v]) {
    if (u == par[v]) continue;
    par[u] = v;
    dfs(u);
  }
}

int n;
int deg[N];

bool check(int v) {
  par[v] = -1;
  dfs(v);
  memset(deg, -1, sizeof deg);
  for (int i = 0; i < n; ++i) {
    int d = lv[i];
    if (deg[d] == -1)
      deg[d] = (int)g[i].size();
    if (deg[d] != (int)g[i].size())
      return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end(), [](int u, int v) {
      return g[u].size() > g[v].size();
    });
  }
  par[0] = -1;
  dfs(0);
  int r = 0;
  for (int i = 1; i < n; ++i)
    if (lv[i] > lv[r])
      r = i;
  par[r] = -1;
  dfs(r);
  int s = 0;
  for (int i = 1; i < n; ++i)
    if (lv[i] > lv[s])
      s = i;
  int d = lv[s];
  int cntr = s, up = d / 2;
  while (up--) {
    cntr = par[cntr];
  }
  if (check(cntr)) {
    printf("%d\n", cntr + 1);
    return 0;
  }
  par[cntr] = -1;
  dfs(cntr);
  map<int, int> cand;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() != 1) continue;
    int now = i;
    bool ok = 1;
    while (now != cntr) {
      if (g[now].size() > 2) {
        ok = 0;
        break;
      }
      now = par[now];
    }
    if (!ok) {
      continue;
    }
    cand[lv[i]] = i;
  }
  int iter = 0;
  for (auto it : cand) {
    if (check(it.second)) {
      printf("%d\n", it.second + 1);
      return 0;
    }
    ++iter;
    if (iter > 2)
      break;
  }
  puts("-1");
  return 0;
}
