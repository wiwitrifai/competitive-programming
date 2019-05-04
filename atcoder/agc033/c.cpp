#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];

int d[N];

void dfs(int v, int par = -1) {
  if (par == -1)
    d[v] = 0;
  else
    d[v] = d[par] + 1;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
  }
}

int grund[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  int root = 0;
  for (int i = 0; i < n; ++i)
    if (d[i] > d[root])
      root = i;
  dfs(root);
  int dia = 0;
  for (int i = 0; i < n; ++i)
    dia = max(dia, d[i]);
  ++dia;
  grund[0] = 0;
  grund[1] = 1;
  for (int i = 2; i <= dia; ++i) {
    grund[i] = 0;
    set<int> st;
    if (i > 2)
      st.insert(grund[i-2]);
    st.insert(grund[i-1]);
    for (int x : st)
      grund[i] += x == grund[i];
  }
  puts(grund[dia] ? "First" : "Second");

  return 0;
}
