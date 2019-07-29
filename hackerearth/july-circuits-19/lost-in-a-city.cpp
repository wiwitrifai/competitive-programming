#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int val[N];
int ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    assert(n < N);
    --s;
    for (int i = 0; i < n; ++i) {
      scanf("%d", val+i);
      g[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      assert(max(u, v) < n);
      assert(min(u, v) >= 0);
      g[u].push_back(v);
    }
    fill(ans, ans+n, int(1e9+7));
    ans[s] = val[s];
    priority_queue<pair<int, int>> pq;
    pq.emplace(-ans[s], s);
    while (!pq.empty()) {
      int v = pq.top().second, w = -pq.top().first;
      pq.pop();
      if (ans[v] != w)
        continue;
      for (int u : g[v]) {
        int res = max(ans[v], val[u]);
        if (ans[u] > res) {
          ans[u] = res;
          pq.emplace(-res, u);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}
