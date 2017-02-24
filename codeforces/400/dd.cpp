#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector< pair<int, int> > adj[N];
int r[N], col[N];
vector< int > saklar[N];

bool dfs(int v, int par = -1) {
  for (auto it : adj[v]) if (it.first != par) {
    int u = it.first, c = it.second;
    if (col[u] == -1) {
      col[u] = col[v] ^ c;
      if (!dfs(u, v))
        return false;
    }
    else if ((col[v] ^ c) != col[u])
      return false;
  }
  return true;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", r+i);
    r[i] = !r[i];
  }
  for (int i = 0; i < m; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      x--;
      saklar[x].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    int u = saklar[i][0], v = saklar[i][1];
    adj[u].emplace_back(v, r[i]);
    adj[v].emplace_back(u, r[i]);
  }
  memset(col, -1, sizeof col);
  bool ok = 1;
  for (int i = 0; i < m; i++) if (col[i] == -1) {
    col[i] = 0;
    if (!dfs(i)) {
      ok = 0;
      break;
    }
  }
  for (int i = 0; i < m; i++)
    cerr << col[i] << " ";
  cerr << endl;
  puts(ok ? "YES" : "NO");
  return 0;
}