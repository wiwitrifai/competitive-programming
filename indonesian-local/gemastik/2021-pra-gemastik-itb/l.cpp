#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  priority_queue<int> pq;
  pq.push(0);
  vector<bool> vis(n, false);
  vector<int> ans;
  while (!pq.empty()) {
    int v = -pq.top();
    pq.pop();
    if (vis[v]) continue;
    vis[v] = true;
    ans.push_back(v);
    for (int u : g[v]) {
      pq.push(-u);
    }
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i] + 1, i + 1 == (int)ans.size() ? '\n' : ' ');
  }
  return 0;
}
