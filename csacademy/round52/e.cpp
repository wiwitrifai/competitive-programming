#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
bool live[N];
vector<int> gv[N];

int dfs(int v, int par = -1, int lv = 0) {
  gv[lv].push_back(v);
  int ret = lv;
  for (int u : g[v]) if (u != par && live[u]) {
    ret = max(ret, dfs(u, v, lv+1));
  }
  return ret;
}

int ans = 0;
int n;
int process(int v) {
  for (int i = 0; i < n; i++)
    gv[i].clear();
  int d = dfs(v);
  while (d > 0 && gv[d].size() == 1) {
    ans++;
    live[gv[d].back()] = 0;
    gv[d].clear();
    d--;
  }
  v = gv[d].back();
  return v;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fill(live, live+n, 1);
  int d = dfs(0);
  int v = gv[d].back();
  for (int i = 0; i <= d; i++)
    gv[i].clear();
  ans = 0;
  v = process(v);
  process(v);
  printf("%d\n", ans);
  return 0;
}