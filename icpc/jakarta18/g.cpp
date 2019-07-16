#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int g[N][N];
int d[N], match[N];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u][v] = 1;
    g[v][u] = 1;
    ++d[u];
    ++d[v];
  }
  for (int i = 0; i < n; ++i)
    g[i][i] = 1;
  int ans = n+n;
  for (int i = 0; i < n; ++i) {
    match[i] = -1;
    for (int j = 0; j < n; ++j) {
      if (g[i][j]) continue;
      if (match[i] == -1 || d[j] > d[match[i]])
        match[i] = j;
    }
  }
  while (1) {
    int sel = -1, cur = 0;
    for (int i = 0; i < n; ++i) {
      if (match[i] == -1) continue;
      if (sel == -1 || d[i] + d[match[i]] > cur)
        sel = i, cur = d[i] + d[match[i]];
    }
    if (sel == -1)
      break;
    ans = min(ans, cur);
    int v = match[sel];
    g[sel][v] = g[v][sel] = 1;
    ++d[sel];
    ++d[v];
    match[v] = -1;
    for (int i = 0; i < n; ++i) {
      if (g[i][v]) continue;
      if (d[match[i]] < d[v])
        match[i] = v;
      if (match[v] == -1 || d[match[v]] < d[i])
        match[v] = i;
    }
    match[sel] = -1;
    for (int i = 0; i < n; ++i) {
      if (g[i][sel]) continue;
      if (d[match[i]] < d[sel])
        match[i] = sel;
      if (match[sel] == -1 || d[match[sel]] < d[i])
        match[sel] = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}