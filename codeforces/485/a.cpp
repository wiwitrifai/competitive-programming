#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int a[N], n, m, k, s;
int d[N][101];

int main() {
  scanf("%d %d %d %d", &n, &m, &k, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i); --a[i];
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(d, -1, sizeof d);
  for (int c = 0; c < k; ++c) {
    queue<int> que;
    for (int i = 0; i < n; ++i) {
      if (a[i] == c) {
        que.push(i);
        d[i][c] = 0;
      }
    }
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int u : g[v]) {
        if (d[u][c] != -1) continue;
        d[u][c] = d[v][c] + 1;
        que.push(u);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    sort(d[i], d[i]+k);
    long long sum = 0;
    for (int j = 0; j < s; ++j)
      sum += d[i][j];
    printf("%lld%c", sum, i == n-1 ? '\n' : ' ');
  }
  return 0;
}