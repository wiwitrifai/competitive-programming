#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, inf = 1e8 + 7;

int dp[N][2][5], tmp[2][5], res[2][5];
char s[N];
vector<int> g[N];

inline void upd(int & var, int val) {
  if (var > val)
    var = val;
}

void combine(int par[2][5], int ch[2][5], int cp, int cc, int to[2][5]) {
  for (int i = 0; i < 2; ++i) {
    upd(to[i][0], par[i][0] + ch[cc][0]);

    upd(to[i][1], par[i][1] + ch[cc][0]);
    upd(to[i^1][1], par[i][1] + ch[cc][1] + 1);

    upd(to[i][2], par[i][2] + ch[cc][0]);
    upd(to[i^1][2], par[i][2] + ch[cc][1] + 1);
    upd(to[i][2], par[i][1] + ch[cc][2]);

    upd(to[i][3], par[i][3] + ch[cc][0]);
    upd(to[i^1][3], par[i][3] + ch[cc][1] + 1);
    upd(to[i][3], par[i][2] + ch[cc][2]);
    upd(to[i][3], par[i][1] + ch[cc^1][3] + 1);
    upd(to[i][3], par[i][1] + ch[cc^1][2] + 1);
    upd(to[i][3], par[i][2] + ch[cc][0]);
    upd(to[i^1][3], par[i][2] + ch[cc][1] + 1);

    upd(to[i][4], par[i][4] + ch[cc][0]);
    upd(to[i][4], par[i][0] + ch[cc][4]);
    upd(to[i][4], par[i][0] + ch[cc][3]);
    upd(to[i][4], par[i][0] + ch[cc][2]);
    upd(to[i][4], par[i][0] + ch[cc][1]);
    upd(to[i][4], par[i][0] + ch[cc][0]);
  }
  cc ^= 1;
  for (int i = 0; i < 2; ++i) {
    upd(to[i][1], par[i^1][1] + ch[cc][0] + 2);
    upd(to[i^1][1], par[i^1][1] + ch[cc][1] + 1 + 2);

    upd(to[i][2], par[i^1][2] + ch[cc][0] + 2);
    upd(to[i^1][2], par[i^1][2] + ch[cc][1] + 1 + 2);
    upd(to[i][2], par[i^1][1] + ch[cc][2] + 2);

    upd(to[i][3], par[i^1][3] + ch[cc][0] + 2);
    upd(to[i^1][3], par[i^1][3] + ch[cc][1] + 1 + 2);
    upd(to[i][3], par[i^1][2] + ch[cc][2] + 2);
    upd(to[i][3], par[i^1][1] + ch[cc^1][3] + 1 + 2);
    upd(to[i][3], par[i^1][1] + ch[cc^1][2] + 1 + 2);
    upd(to[i][3], par[i^1][2] + ch[cc][0] + 2);
    upd(to[i^1][3], par[i^1][2] + ch[cc][1] + 1 + 2);
  }

}

void dfs(int v, int p) {
  for (int u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 5; ++j) {
      tmp[i][j] = inf;
    }
  }
  tmp[0][0] = 0;
  tmp[1][1] = 1;
  tmp[1][2] = 1;
  tmp[1][3] = 1;
  tmp[0][4] = 0;
  for (int u : g[v]) {
    if (u == p) continue;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 5; ++j) {
        res[i][j] = inf;
      }
    }
    combine(tmp, dp[u], s[v], s[u], res);
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 5; ++j) {
        tmp[i][j] = res[i][j];
      }
    }
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 5; ++j) {
      dp[v][i][j] = tmp[i][j];
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    s[i] = s[i] == '0';
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int v = 0;
  dfs(v, v);
  int ans = inf;
  for (int i = 0; i < 5; ++i) {
    upd(ans, dp[v][(int)s[v]][i]);
  }
  printf("%d\n", ans);
  return 0;
}
