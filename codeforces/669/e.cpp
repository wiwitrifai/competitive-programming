#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector<pair<int, int>> g[N];
int dist[N][2];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, t;
    scanf("%d %d %d", &u, &v, &t);
    --u, --v;
    g[v].emplace_back(u, t);
  }
  memset(dist, -1, sizeof dist);
  dist[n-1][0] = dist[n-1][1] = 0;
  queue<int> que;
  que.push(n-1);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    int now = max(dist[v][0], dist[v][1]);
    for (auto & e : g[v]) {
      int u = e.first, t = e.second;
      if (dist[u][t] == -1) {
        dist[u][t] = now + 1;
        if (dist[u][0] != -1 && dist[u][1] != -1) {
          que.push(u);
        }
      }
    }
  }
  int ans = (dist[0][0] == -1 || dist[0][1] == -1) ? -1 : max(dist[0][0], dist[0][1]);
  printf("%d\n", ans);
  for (int i = 0; i < n; ++i) {
    int res = 0;
    if (dist[i][0] == -1)
      res = 0;
    else if (dist[i][1] == -1)
      res = 1;
    else
      res = dist[i][1] > dist[i][0];
    printf("%d", res);
  }
  printf("\n");
  return 0;
}
