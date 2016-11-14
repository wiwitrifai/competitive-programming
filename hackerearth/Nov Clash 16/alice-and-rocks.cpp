#include <bits/stdc++.h>

using namespace std;

const int N = 505, M = N * N;

int x[N][N];
vector< int > adj[M];
bool vis[M];
int match[M], matched[M];

bool dfs(int v) {
  if (vis[v])
    return false;
  vis[v] = 1;
  for (int u : adj[v])
    if (match[u] == -1 || dfs(match[u]))
      return match[u] = v, true;
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int  i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        x[i][j] = 0;
    for (int i = 0; i < k; i++) {
      int r, c;
      scanf("%d %d", &r, &c);
      r--; c--;
      x[r][c] = -1; 
    }
    int row = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (x[i][j] == -1) {
          if (ok)
            row++, ok = false;
        }
        else
          x[i][j] = row, ok = true;
      }
      if (ok)
        row++, ok = false;
    }
    for (int i = 0; i < row; i++)
      adj[i].clear();
    int col = 0;
    ok = false;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (x[j][i] == -1) {
          if (ok) col++, ok = false;
        }
        else
          adj[x[j][i]].push_back(col), ok = true;
      }
      if (ok)
        col++, ok = false;
    }
    for (int i = 0; i < col; i++)
      match[i] = -1;
    for (int i = 0; i < row; i++)
      matched[i] = -1;
    int ans = 0;
    while(true){
      fill(vis, vis+row, 0);
      bool fnd = false;
      for(int i = 0; i < row; i++) if(matched[i] == -1 && !vis[i]) {
        bool res = dfs(i);
        fnd |= res;
        if (res)
          matched[i] = 1;
        ans += res;
      }
      if(!fnd)
        break;
    }
    printf("%d\n", ans);
  }
  return 0;
}