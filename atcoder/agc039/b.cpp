#include <bits/stdc++.h>

using namespace std;

const int N = 222;

char s[N][N];
int n, dist[N];
bool done[N];

void bfs(int v) {
  memset(dist, -1, sizeof dist);
  dist[v] = 0;
  queue<int> que;
  que.push(v);
  while (!que.empty()) {
    v = que.front(); que.pop();
    for (int j = 0; j < n; ++j) {
      if (s[v][j] == '0') continue;
      if (dist[j] != -1) continue;
      dist[j] = dist[v] + 1;
      que.push(j);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    bfs(i);
    bool ok = 1;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (s[j][k] == '0') continue;
        ok &= abs(dist[j] - dist[k]) == 1;
      }
    }
    if (ok)
      ans = max(ans, 1 + * max_element(dist, dist+n));
  }
  printf("%d\n", ans);
  return 0;
}
