#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

bool vis[N][10];
vector< pair< int, int > > adj[N];
long long ans[10], cnt[10];
bool mark[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--; v--;
    w %= 10;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, (10 - w) % 10);
  }
  for (int r = 0; r < n; r++) if (!mark[r]) {
    queue<pair< int, int >> que;
    que.push(make_pair(r, 0));
    vis[r][0] = 1;
    vector< int > visited;
    while (!que.empty()) {
      int u = que.front().first, w = que.front().second;
      if (!mark[u]) {
        mark[u] = 1;
        visited.push_back(u);
      }
      que.pop();
      for (auto it : adj[u]) {
        int v = it.first, nw = w + it.second;
        if (nw >= 10)
          nw -= 10;
        if (vis[v][nw]) continue;
        que.push(make_pair(v, nw));
        vis[v][nw] = 1;
      }
    }
    memset(cnt, 0, sizeof cnt);
    for (int i : visited)
      for (int j = 0; j < 10; j++)
        cnt[j] += vis[i][j];
    for (int i : visited) {
      for (int j = 0; j < 10; j++) if (vis[i][j]) {
        int k = 10 - j;
        if (k >= 10) k -= 10;
        for (int z = 0; z < 10; z++) {
          int nz = k + z;
          if (nz >= 10) nz -= 10;
          ans[nz] += cnt[z] - vis[i][z];
        }
        break;
      }
    }
  }
  // ans[0] -= n;
  for (int i = 0; i < 10; i++)
    printf("%lld\n", ans[i]);
  return 0;
}