#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int dist[N][N], a[N][N];
int p[N * N];

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n * n; ++i) {
    scanf("%d", p+i);
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = min(min(i+1, n-i), min(j+1, n-j));
      a[i][j] = 1;
    }
  }
  int nn = n * n;
  int ans = 0;
  for (int i = 0; i < nn; ++i) {
    int v = p[i];
    queue<int> que;
    int r = v / n, c = v % n;
    --dist[r][c];
    a[r][c] = 0;
    ans += dist[r][c];
    que.emplace(v);
    while (!que.empty()) {
      v = que.front();
      que.pop();
      r = v / n, c = v  % n;
      for (int j = 0; j < 4; ++j) {
        int x = r + dr[j], y = c + dc[j];
        if (min(x, y) < 0 || max(x, y) >= n) continue;
        if (dist[x][y] > dist[r][c] + a[x][y]) {
          dist[x][y] = dist[r][c] + a[x][y];
          que.emplace(x * n + y);
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
