#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> h(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &h[i]);
  stack<int> up, down;
  vector<vector<int>> g(n);
  auto addEdge = [&](int u, int v) {
    if (u > v)
      swap(u, v);
    g[u].push_back(v);
  };
  for (int i = 0; i < n; ++i) {
    int last = -1;
    while (!up.empty() && h[up.top()] <= h[i]) {
      addEdge(up.top(), i);
      last = h[up.top()];
      up.pop();
    }
    if (!up.empty() && last != h[i])
      addEdge(up.top(), i);
    up.push(i);
    last = -1;
    while (!down.empty() && h[down.top()] >= h[i]) {
      addEdge(down.top(), i);
      last = h[down.top()];
      down.pop();
    }
    if (!down.empty() && last != h[i])
      addEdge(down.top(), i);
    down.push(i);
  }
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
    g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
  }
  queue<int> que;
  que.push(0);
  vector<int> dist(n, -1);
  dist[0] = 0;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int u : g[v]) {
      if (dist[u] != -1) continue;
      dist[u] = dist[v] + 1;
      que.push(u);
    }
  }
  printf("%d\n", dist[n-1]);
  return 0;
}
