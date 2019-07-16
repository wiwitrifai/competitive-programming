#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<int> g[N];
char s[N];
int cnt[N];
int cntr, numCC;
int num[N], low[N], vis[N], cc[N];
vector<int> S;

void dfs(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : g[v]) {
    if(num[u] == -1)
      dfs(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cc[u] = numCC;
      if(u == v)
        break;
    }
    ++numCC;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (s[u] == s[v]) {
      g[u].push_back(v+n);
      g[v].push_back(u+n);
    }
    else {
      g[u+n].push_back(v);
      g[v+n].push_back(u);
    }
  }
  numCC = 0;
  memset(num, -1, sizeof num);
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < 2 * n; ++i) {
    if (num[i] != -1) continue;
    dfs(i);
  }
  bool ok = numCC < 2 * n;
  puts(ok ? "Yes" : "No");
  return 0;
}