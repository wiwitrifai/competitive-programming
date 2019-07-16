#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int g[N][N];
int din[N], p[N];
long long dp[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (u > v) swap(u, v);
    ++din[u];
    g[v][u] = 1;
  }
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    if (din[i] == 0)
      pq.push(-i);
  }
  memset(p, -1, sizeof p);
  int cur = 1;
  while (!pq.empty()) {
    int v = -pq.top();
    p[v] = cur++;
    pq.pop();
    for (int u = 0; u < n; ++u) if (g[v][u]) {
      --din[u];
      if (din[u] == 0) {
        pq.push(-u);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    assert(p[i] >= 0);
    for (int j = i+1; j < n; ++j) {
      assert(g[j][i] == (p[i] > p[j]));
    }
  }
  long long ans = 1;
  p[n] = n+1;
  int big = n+2;
  for (int i = 0; i < n; ++i)
    if (p[i] < cur) {
      ++dp[i];
      cur = p[i];
    }
  for (int i = 0; i < n; ++i) {
    big = n+2;
    for (int j = i+1; j <= n; ++j) {
      if (p[i] < p[j] && p[j] < big) {
        dp[j] += dp[i];
        big = p[j];
      }
    }
  }
  printf("%lld\n", dp[n]);
  return 0;
}