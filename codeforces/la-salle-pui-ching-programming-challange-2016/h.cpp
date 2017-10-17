#include <bits/stdc++.h>

using namespace std;

const int N = 1024, M = N * 10;

vector<pair<int, int> > g[N];
pair<int, int> pre[N][M];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
      pre[i][j] = {-1, -1};
  int a, b;
  scanf("%d %d", &a, &b);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u,&v, &w);
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  queue<pair<int, int> > st;
  st.push(make_pair(0, b));
  pre[b][0] = {b, 0};
  while (!st.empty()) {
    auto it = st.front();
    int w = it.first, v = it.second;
    st.pop();
    for (auto nx : g[v]) {
      int u = nx.first;
      if (w + nx.second <= k) {
        if (pre[u][w+nx.second].first == -1) {
          pre[u][w+nx.second] = {v, nx.second};
          st.push(make_pair(w+nx.second, u));
        }
      }
    }
  }
  if (pre[a][k].first == -1) {
    puts("Impossible");
  }
  else {
    int now = a, w = k;
    printf("%d", now);
    while (w) {
      pair<int, int> nx = pre[now][w];
      now = nx.first;
      w -= nx.second;
      printf(" %d", now);
    }
    printf("\n");
  }

  return 0;
}