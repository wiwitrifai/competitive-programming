#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int vis[N];
vector<int> g[N];
int n, m, k;

vector<int> cyc;
vector<int> s;

bool dfs(int v) {
  int lv = s.size();
  s.push_back(v);
  vis[v] = lv;
  for (int u : g[v]) {
    if (vis[u] == -1) {
      return dfs(u);
    }
    if (lv - vis[u]+1 >= k) {
      for (int i = vis[u]; i <= lv; ++i)
        cyc.push_back(s[i]);
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
      g[i].clear();
      vis[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v); --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      if (g[i].size() < k) {
        ans = i;
      }
    }
    if (ans != -1) {
      puts("CUT");
      printf("1\n%d\n", ans+1);
      continue;
    }
    cyc.clear();
    bool res = dfs(0);
    assert(res);
    puts("CYCLE");
    printf("%d\n", cyc.size());
    for (int i = 0; i < cyc.size(); ++i)
      printf("%d%c", cyc[i] + 1, i+1 == cyc.size() ? '\n' : ' ');
  }
  return 0;
}