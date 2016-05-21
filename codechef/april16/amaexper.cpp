#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> adj[N];
int p[N], up[N], ans[N], n, dd[N];

void dfs(int v, int par = -1, int val = 0) {
  p[v] = par;
  up[v] = val;
  for(auto nx : adj[v]) if(nx.first != par) {
    dfs(nx.first, v, nx.second);
  }
}

pair<int, int> dfs2(int v, int par = -1) {
  int down = 0, opt, sdown = 0;
  for(auto nx : adj[v]) if(nx.first != par) {
    pair<int, int> res = dfs2(nx.first, v);
    if(res.first + nx.second > down) {
      sdown = down;
      down = res.first + nx.second;
      opt = res.second;
    }
    else if(res.first + nx.second > sdown) {
      sdown = res.first + nx.second;
    }
  }
  dd[v] = down;
  if(sdown == down) {
    ans[v] = sdown;
    return {down, v};
  }
  else {
    ans[v] = max(down, sdown);
    sdown += down;
    while(true) {
      int h = dd[opt];
      ans[v] = min(ans[v], max(sdown - h, h));
      if(max(sdown-h, h) > max(sdown-h-up[opt], h+up[opt])) {
        h += up[opt];
        opt = p[opt];
      }
      else
        break;
    }
    return {down, opt};
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
      adj[i].clear();
    for(int i = 1; i<n; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--; v--;
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
    dfs(0);
    dfs2(0);
    for(int i = 0; i<n; i++)
      printf("%d\n", ans[i]);
  }
  return 0;
}