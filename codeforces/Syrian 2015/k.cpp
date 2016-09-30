#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int d[N], p[N], n, k, c, da[N], val[N];

vector< int > adj[N];

void dfs(int v = 0) {
  d[v] = 0;
  for (int u : adj[v]) {
    dfs(u);
    d[v] = max(d[v], d[u] + 1);
  }
}

void dfs2(int v = 0, int dd = 0) {
  da[v] = max(d[v], dd);
  int ma = 0;
  val[adj[v].size()] = ma;
  for (int j = (int)adj[v].size() - 1; j >= 0; j--) {
    ma = max(d[adj[v][j]] + 1, ma);
    val[j] = ma;
  }
  for (int j = 0; j < (int)adj[v].size(); j++) {
    dfs2(adj[v][j], max(dd, val[j+1]) + 1);
    dd = max(d[adj[v][j]] + 1, dd);
  }
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &c, &k);
    double a = 0, b = 0, ps = N;
    while (c--) {
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
        adj[i].clear();
      for (int i = 1; i < n; i++) {
        scanf("%d", p+i);
        p[i]--;
        adj[p[i]].push_back(i);
      }
      dfs();
      dfs2();
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        cnt += da[i] <= k;
      }
      double success = (double)ps * cnt/n, fail = (double)ps * (n-cnt)/n;
      a += fail;
      b += fail * 4 + success;
      ps = success;
    }
    a = (double)N - a;
    printf("%.4lf\n", b/a);
  }

  return 0;
}