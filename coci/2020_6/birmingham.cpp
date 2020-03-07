#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

vector<int> g[N];

int main() {
  int n, m, q, k;
  scanf("%d %d %d %d", &n, &m, &q, &k);
  set<int> sources;
  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    sources.insert(x);
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> dist(n, inf);
  queue<int> que;
  for (int x : sources) {
    dist[x] = 0;
    que.push(x);
  }
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int u : g[v]) {
      if (dist[u] != inf) continue;
      dist[u] = dist[v] + 1;
      que.push(u);
    }
  }
  vector<int> conv(n+1, 0);
  for (int i = 1, sum = 0; sum < n; ++i) {
    int nxt = sum + i;
    while (sum < n && sum < nxt) {
      ++sum;
      conv[sum] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    int ans = conv[(dist[i] + k - 1) / k];
    printf("%d%c", ans, i+1 == n ? '\n' : ' ');
  }
  return 0;
}
