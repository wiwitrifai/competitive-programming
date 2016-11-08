#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int dist[N], d[N];
vector< int > adj[N];

int main() {
  freopen("jumping.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      adj[i].clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", d+i);
      if (i-d[i] >= 0)
        adj[i-d[i]].push_back(i);
      if (i+d[i] < n)
        adj[i+d[i]].push_back(i);
    }
    queue<int> que;
    memset(dist, -1, sizeof dist);
    dist[n-1] = 0;
    que.push(n-1);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (int u : adj[v]) if (dist[u] == -1) {
        dist[u] = dist[v] + 1;
        que.push(u);
      }
    }
    for (int i = 0; i< n; i++)
      printf("%d\n", dist[i]);
  }

  return 0;
}