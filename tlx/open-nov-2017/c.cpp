#include <bits/stdc++.h>

using namespace std;

const int N = 2048, inf = 1e9 + 7;

int dist[N];
long long x[N], y[N], d[N];

bool can(int i, int j, long long jangkau) {
  if (y[i] > y[j]) {
    long long dx = x[i] - x[j], dy = y[i] - y[j];
    long long dd = dx * dx + dy * dy;
    return dd <= jangkau * jangkau;
  }
  else if ((y[i] + d[i]) < y[j]) {
    long long dx = x[i] - x[j], dy = y[i] + d[i] - y[j];
    long long dd = dx * dx + dy * dy;
    return dd <= jangkau * jangkau;
  }
  return abs(x[i] - x[j]) <= jangkau;
}

int main() {
  int n;
  long long r, l;
  scanf("%d %lld %lld", &n, &r, &l);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld %lld", x+i, y+i, d+i);
    dist[i] = inf;
  }
  dist[0] = 0;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    long long cur = r - 1LL * l * dist[v];
    if (cur < 0) continue;
    for (int u = 0; u < n; u++) {
      if (dist[u] <= dist[v] + 1) continue;
      if (!can(v, u, cur)) continue;
      dist[u] = dist[v] + 1;
      que.push(u);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] == inf) continue;
    // cerr << i << endl;
    ans = max(ans, (long long) y[i] + d[i]);
  }
  printf("%lld\n", ans);
  return 0;
}