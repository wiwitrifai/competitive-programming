#include <bits/stdc++.h>

using namespace std;

const int N = 1024, B = 105, V = 2e5 + 5, inf = 1e9 + 7;

int x[N], y[N];
int sqrtval[V];
vector<tuple<int, int, int> > g[N];
int c[N];

int dist(int u, int v) {
  int dx = x[u] - x[v], dy = y[u] - y[v];
  int d2 = dx * dx + dy * dy;
  return sqrtval[d2];
}

void add(int u, int v, int cost) {
  int d = dist(u, v);
  cost *= d;
  g[u].emplace_back(v, d, cost);
  g[v].emplace_back(u, d, cost);
}

int ans[N][B];

int main() {
  for (int i = 0, j = 0; i < V; ++i) {
    while (j * j < i) ++j;
    assert(j * j >= i);
    sqrtval[i] = j;
  }
  int xs, ys, xd, yd, n, b, c0, t;
  scanf("%d %d %d %d", &xs, &ys, &xd, &yd);
  scanf("%d %d %d", &b, &c0, &t);
  for (int i = 1; i <= t; ++i) {
    scanf("%d", c+i);
  }
  scanf("%d", &n);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < n; ++i) {
    int l;
    scanf("%d %d %d", x+i, y+i, &l);
    for (int j = 0; j < l; ++j) {
      int u, mu;
      scanf("%d %d", &u, &mu);
      edges.emplace_back(i, u, c[mu]);
    }
  }
  x[n] = xs;
  y[n] = ys;
  x[n+1] = xd;
  y[n+1] = yd;
  for (auto e : edges) {
    int u, v, cmu;
    tie(u, v, cmu) = e;
    add(u, v, cmu);
  }
  add(n, n+1, c0);
  for (int i = 0; i < n; ++i) {
    add(n, i, c0);
    add(i, n+1, c0);
  }
  for (int i = 0; i <= n+1; ++i)
    for (int j = 0; j <= b; ++j)
      ans[i][j] = inf;
  ans[n][0] = 0;
  priority_queue<tuple<int, int, int>> pq;
  pq.emplace(0, n, 0);
  while (!pq.empty()) {
    int now, v, d;
    tie(now, v, d) = pq.top();
    pq.pop();
    now = -now;
    if (ans[v][d] != now) continue;
    for (auto it : g[v]) {
      int u, dis, cost;
      tie(u, dis, cost) = it;
      if (d + dis > b) continue;
      int & cur = ans[u][d+dis];
      cost += now;
      if (cur > cost) {
        cur = cost;
        pq.emplace(-cur, u, d+dis);
      }
    }
  }
  int answer = inf;
  for (int i = 0; i <= b; ++i) {
    answer = min(answer, ans[n+1][i]);
  }
  if (answer >= inf)
    answer = -1;
  printf("%d\n", answer);
  return 0;
}
