#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> g[N];

int d[N];
int vis[N];
bool ok[N];
int a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", d+i);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    a[i] = u;
    b[i] = v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> nodes(n);
  for (int i = 0; i < n; ++i)
    nodes[i] = i;
  sort(nodes.begin(), nodes.end(), [](int l, int r) {
    return d[l] < d[r];
  });
  for (int v : nodes) {
    if (vis[v]) continue;
    queue<int> que;
    vis[v] = 1;
    que.push(v);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int w : g[u]) {
        if (vis[w] || d[w] < d[u])
          continue;
        vis[w] = -vis[u];
        que.push(w);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int u = a[i], v = b[i];
    if (vis[u] != vis[v]) {
      if (d[u] == max(d[u], d[v]))
        ok[u] = 1;
      if (d[v] == max(d[u], d[v]))
        ok[v] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!ok[i]) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%c", vis[i] > 0 ? 'B' : 'W');
  }
  printf("\n");
  for (int i = 0; i < m; ++i)
    printf("%d\n", max(d[a[i]], d[b[i]]));
  return 0;
}
