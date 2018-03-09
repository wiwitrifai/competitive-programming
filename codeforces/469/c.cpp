#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > num, low, S, vis, elem[N], g[N];
int cc[N], out[N];
int cntr, numCC;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : g[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cc[u] = numCC;
      elem[numCC].push_back(u);
      if(u == v)
        break;
    }
    ++numCC;
  }
}

int d[N];

int main() {
  int n, m, h;
  scanf("%d %d %d", &n, &m, &h);
  for (int i = 0; i < n; ++i)
    scanf("%d", d+i);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (((d[u]+1) % h) == d[v])
      g[u].push_back(v);
    swap(u, v);
    if (((d[u]+1) % h) == d[v])
      g[u].push_back(v);
  }
  num.assign(n, -1);
  low.assign(n, -1);
  vis.assign(n, 0);
  S.clear();
  cntr = numCC = 0;
  for (int i = 0; i < n; ++i) if (num[i] == -1) {
    tarjanSCC(i);
  }
  for (int i = 0; i < n; ++i) {
    for (int u : g[i]) if (cc[i] != cc[u])
      out[cc[i]] = 1;
  }
  int ans = -1;
  for (int i = 0; i < numCC; ++i) {
    if (out[i]) continue;
    if (ans == -1 || elem[ans].size() > elem[i].size())
      ans = i;
  }
  printf("%d\n", elem[ans].size());
  sort(elem[ans].begin(), elem[ans].end());
  for (int u : elem[ans]) {
    printf("%d ", u+1);
  }
  printf("\n");
  return 0;
}