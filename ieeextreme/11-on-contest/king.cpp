#include <bits/stdc++.h>

using namespace std;

const int N = 104, inf = 1e7 + 5;

int n, m;
int to[N][N];
int d[N][N], dp[N][N];
vector<pair<int, int> > vp[N * N];

int a, b;

int go(int x) {
  assert(1 <= x && x <= n);
  assert(d[x][b] <= 1);
  printf("%d\n", x);
  fflush(stdout);
  b = x;
  int v;
  if (a != b) {
    scanf("%d", &v);
    a = v;
    return false;
  }
  return true;
}

bool cmp(pair<int, int> le, pair<int, int> ri) {
  return dp[le.first][le.second] < dp[ri.first][ri.second];
}

vector<int> g[N];

int main() {
  scanf("%d %d", &n, &m);
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      d[i][j] = (i == j) ? 0 : inf;
    }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
    d[u][v] = 1;
    d[v][u] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n;j++) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  int ddma = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      vp[d[i][j]].emplace_back(i, j);
      dp[i][j] = (i == j) ? 0 : inf;
      ddma = max(d[i][j], ddma);
      if (d[i][j] == 1)
        dp[i][j] = 1;
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (dp[i][j] <= 1)
        to[i][j] = j;
      else
        to[i][j] = i;
  }
  for (int dd = 0; dd <= ddma; dd++) {
    bool ok = 1;
    while (ok) {
      ok = 0;
      sort(vp[dd].begin(), vp[dd].end(), cmp);
      for (auto it : vp[dd]) {
        for (int u : g[it.first]) {
          int v = it.second;
          for (int w : g[it.second]) {
            if (dp[u][w] > dp[u][v]) {
              v = w;
            }
          }
          if (dp[it.first][it.second] > dp[u][v] + 2) {
            // cerr << it.first << " " << it.second << " " << u << " " << v << " " << dp[u][v] << endl;
            dp[it.first][it.second] = dp[u][v] + 2;
            to[it.first][it.second] = u;
            ok = 1;
          }
        }
      }
    }

  }

  int v = 1, dm = inf;
  for (int i = 1; i <= n; i++) {
    int dma = 0;
    for (int j = 1; j <= n; j++) {
      // cerr << dp[i][j] << " ";
      dma = max(dma, dp[i][j]);
      assert(dp[i][j] < inf);
    }
    // cerr << endl;
    if (dma < dm)
      v = i, dm = dma;
  }
  a = -1;
  b = v;
  while (!go(v)) {
    v = to[b][a];
  }
  return 0;
}