#include <bits/stdc++.h>

using namespace std;

const int N = 55, inf = 1e9 + 7;

int hop[N][N], dist[N][N];

vector<pair<int, int>> pos[N * N];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", hop[i]+j);
      pos[hop[i][j]].emplace_back(i, j);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      dist[i][j] = inf;
  }
  for (auto it : pos[1]) {
    dist[it.first][it.second] = 0;
  }
  for (int i = 1; i < k; ++i) {
    for (auto it : pos[i]) {
      int now = dist[it.first][it.second];
      for (auto nx : pos[i+1]) {
        dist[nx.first][nx.second] = min(dist[nx.first][nx.second], now + abs(nx.first - it.first) + abs(nx.second - it.second));
      }
    }
  }
  int ans = inf;
  for (auto it : pos[k]) {
    ans = min(ans, dist[it.first][it.second]);
  }
  if (ans >= inf)
    ans = -1;
  printf("%d\n",ans);
  return 0;
}
