#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N], low, num, par;
vector<int> vxor;
int Root, cntr;

vector<pair<int, int>> bridges;

void dfs(int v) {
  low[v]= num[v] = ++cntr;
  for(auto e : g[v]) {
    int u = vxor[e] ^ v;
    if(num[u] == -1) {
      par[u] = e;
      dfs(u);
      if(low[u] > num[v]) {
        int a = u, b = v;
        if (a > b)
          swap(a, b);
        bridges.push_back(make_pair(a, b));
      }
      low[v] = min(low[v], low[u]);
    }
    else if(e != par[v])
      low[v] = min(low[v], num[u]);
  }
}

int solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  cntr = 0;
  num.assign(n, -1);
  low.assign(n, 0);
  par.assign(n, -1);
  vxor.assign(m, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].push_back(i);
    g[b].push_back(i);
    vxor[i] = a ^ b;
  }
  for(int i = 0; i < n; i++) if(num[i] == -1) {
    dfs(i);
  }
  sort(bridges.begin(), bridges.end());
  bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());
  printf("%d\n", m - (int)bridges.size());
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
