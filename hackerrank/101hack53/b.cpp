#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int match[N * N], matched[N * N];
bool mark[N * N];
vector<int> adj[N * N];

bool dfs(int v){
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : adj[v])
    if(match[u] == -1 or dfs(match[u]))
      return matched[v] = u, match[u] = v, true;
  return false;
}

bool mati[N][N];
int n, m, a, b;

bool valid(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main() {
  scanf("%d %d %d %d", &n, &m, &a, &b);
  int tot = n * m - a - b;
  if (tot & 1) {
    puts("NO");
    return 0;
  }
  for (int i = 0; i < a; ++i)
    mati[0][i] = 1;
  for (int i = 0; i < b; ++i)
    mati[n-1][m-1-i] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mati[i][j]) continue;
      if ((i+j) & 1) continue;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (!valid(x, y)) continue;
        if (mati[x][y]) continue;
        adj[i * m + j].push_back(x * m + y);
      }
    }
  }
  memset(matched, -1, sizeof matched);
  memset(match, -1, sizeof match);
  while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 0;i < n * m;++i) if(matched[i] == -1 && !mark[i])
      fnd |= dfs(i);
    if(!fnd)
      break;
  }
  int ans = 0;
  for (int i = 0; i < n * m; ++i) if (matched[i] != -1)
    ++ans;
  if (ans != tot/2) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < n * m; ++i) {
    if (matched[i] != -1) {
      int u = i, v = matched[i];
      if (u > v) swap(u, v);
      printf("%d %d %d %d\n", (u / m) + 1, (u % m) + 1, (v/m) + 1, (v % m) + 1);
    }
  }
  return 0;
}