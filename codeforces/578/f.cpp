#include <bits/stdc++.h>

using namespace std;

const int N = 1024, M = 2520;
int ans[N][M];

int n, k[N];
vector<int> e[N];
int vis[N][M];
int ada[N];

int solve(int v, int c) {
  if (ans[v][c] != -1)
    return ans[v][c];
  vector<pair<int, int>> nodes;
  while (vis[v][c] == 0) {
    nodes.emplace_back(v, c);
    vis[v][c] = 1;
    c = (c + k[v]) % M;
    v = e[v][c % e[v].size()];
  }
  int ret = -1;
  if (vis[v][c] == 1) {
    pair<int, int> cur = {v, c};
    reverse(nodes.begin(), nodes.end());
    ret = 0;
    for (auto & it : nodes) {
      ret += !ada[it.first];
      ada[it.first] = 1;
      if (it == cur)
        break;
    }
  }
  else
    ret = ans[v][c];
  for (auto & it : nodes) {
    ans[it.first][it.second] = ret;
    vis[it.first][it.second] = 2;
    ada[it.first] = 0;
  }
  return ret;
}

int main() {
  memset(ans, -1, sizeof ans);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", k+i);
    k[i] %= M;
    if (k[i] < 0)
      k[i] += M;
  }
  for (int i = 0; i < n; ++i) {
    int m;
    scanf("%d", &m);
    e[i].resize(m);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &e[i][j]);
      --e[i][j];
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int v, c;
    scanf("%d %d", &v, &c);
    --v;
    c %= M;
    if (c < 0)
      c += M;
    printf("%d\n", solve(v, c));
  }
  return 0;
}
