#include <bits/stdc++.h>

using namespace std;

const int N = 2020, M = 5e5 + 5;

int a[M], b[M], d[2][N];
int match[N], matched[N];
bool vis[N];

vector< int > adj[N];
bool used[M];

bool dfs(int v) {
  if (vis[v])
    return false;
  vis[v] = 1;
  for (int id : adj[v]) {
    int u = b[id];
    if (match[u] == -1 || dfs(match[u])) {
      matched[v] = id;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", a+i, b+i);
    a[i]--; b[i]--;
    d[0][a[i]]++;
    d[1][b[i]]++;
  }
  memset(match, -1, sizeof match);
  memset(matched, -1, sizeof matched);
  for (int i = 0; i < m; i++) {
    if ((d[0][a[i]] & 1) == 0 || ((d[1][b[i]] & 1) == 0))
      adj[a[i]].push_back(i);
  }
  while (1) {
    memset(vis, false, sizeof vis);
    bool fnd = false;
    for (int i = 0; i < n; i++) if (matched[i] == -1 && !vis[i])
      fnd |= dfs(i);
    if (!fnd)
      break;
  }
  for (int i = 0; i < n; i++)
    if  (matched[i] != -1)
      used[matched[i]] = 1;
  for (int i = 0; i < m; i++) {
    puts(used[i] ? "YES" : "NO");
  }
  return 0;
}