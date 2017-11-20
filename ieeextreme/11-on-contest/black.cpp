#include <bits/stdc++.h>

using namespace std;

const int N = 103, inf = 1e8;

int d[N][N][2], to[N][N];
set<pair<int, pair<int, int> > > st[2];
vector<int> g[N];

int a, b;

int go(int x) {
  int v;
  printf("%d\n", x);
  fflush(stdout);
  b = x;
  if (a != b) {
    scanf("%d", &v);
    a = v;
    return false;
  }
  return true;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        d[i][j][0] = d[i][j][1] = 0;
      else {
        d[i][j][0] = inf;
        to[i][j] = 0;
        d[i][j][1] = -inf;
      }
    }
    st[0].insert(make_pair(0, make_pair(i, i)));
    st[1].insert(make_pair(0, make_pair(i, i)));
  }
  while (!st[0].empty() || !st[1].empty()) {
    while (!st[0].empty()) {
      auto it = st[0].begin();
      int u = it->second.first, v = it->second.second;
      st[0].erase(it);
      for (int x : g[v]) {
        if (d[u][x][1] < d[u][v][0]+1) {
          st[1].erase(make_pair(d[u][x][1], make_pair(u, x)));
          d[u][x][1] = d[u][v][0]+1;
          st[1].insert(make_pair(d[u][x][1], make_pair(u, x)));
        }
      }
    }
    while (!st[1].empty()) {
      auto it = --st[1].end();
      int u = it->second.first, v = it->second.second;
      st[1].erase(it);
      for (int x : g[u]) {
        if (d[x][v][0] > d[u][v][1]+1) {
          st[1].erase(make_pair(d[x][v][0], make_pair(x, v)));
          d[x][v][0] = d[u][v][1]+1;
          to[x][v] = u;
          st[1].insert(make_pair(d[x][v][0], make_pair(x, v)));
        }
      }
    }
  }
  int v = 1, dm = inf;
  for (int i = 1; i <= n; i++) {
    int dma = 0;
    for (int j = 1; j <= n; j++)
      dma = max(dma, d[i][j][0]);
    if (dma < dm)
      v = i, dm = dma;
    assert(dma < inf);
    cerr << dma << endl;
  }
  a = b = -1;
  while (!go(v)) {
    v = to[b][a];
  }
  return 0;
}