#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

int w[N];
vector<int> g[N];
bool used[N];
int vxor[N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", w+i);
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    --w[u], --w[v];
    g[u].push_back(i);
    g[v].push_back(i);
    vxor[i] = u^v;
  }
  vector<int> topo;
  for (int i = 0; i < n; ++i) {
    if (w[i] >= 0)
      topo.push_back(i);
  }
  vector<int> ans;
  for (int i = 0; i < (int)topo.size(); ++i) {
    int v = topo[i];
    for (int e : g[v]) {
      if (used[e]) continue;
      used[e] = true;
      ans.push_back(e);
      int u = v ^ vxor[e];
      ++w[u];
      if (w[u] == 0) {
        topo.push_back(u);
      }
    }
  }
  if ((int)topo.size() < n) {
    puts("DEAD");
    return;
  }
  reverse(ans.begin(), ans.end());
  puts("ALIVE");
  bool first = true;
  for (int e : ans) {
    if (!first) {
      printf(" ");
    }
    first = false;
    printf("%d", e+1);
  }
  printf("\n");
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
