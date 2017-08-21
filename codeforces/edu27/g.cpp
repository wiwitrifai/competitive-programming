#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< pair<int, int > > g[N];
int val[N], n, m;
set< int > b;

void dfs(int v, int c) {
  if (val[v] != -1) {
    b.insert(c ^ val[v]);
    return;
  }
  val[v] = c;
  for (auto it : g[v]) {
    dfs(it.first, c ^ it.second);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  memset(val, -1, sizeof val);
  dfs(0, 0);
  vector< int > ve;
  for (int x : b)
    ve.push_back(x);
  for (int i = 0; i < min(32, (int)ve.size()); i++) {
    int big = i;
    for (int j = i; j < ve.size(); j++) {
      if (ve[j] > ve[big])
        big = j;
    }
    swap(ve[i], ve[big]);
    for (int j = 0; j < ve.size(); j++) {
      if (i == j) continue;
      ve[j] = min(ve[j], ve[j] ^ ve[i]);
    }
  }
  int ans = val[n-1];
  for (int i = 0; i < ve.size(); i++) {
    ans = min(ans, ans ^ ve[i]);
  }
  printf("%d\n", ans);
  return 0;
}