#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

char s[N][N];

int val[N][N];

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  queue<pair<int, int>> que;
  memset(val, -1, sizeof val);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      bool ok = true;
      for (int k = 0; k < 4; ++k) {
        int rr = i + dr[k], cc = j + dc[k];
        if (rr < 0 || rr >= n || cc < 0 || cc >= m || s[rr][cc] != s[i][j]) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        val[i][j] = 1;
        que.emplace(i, j);
      }
    }
  }
  while (!que.empty()) {
    int r = que.front().first, c = que.front().second;
    que.pop();
    for (int k = 0; k < 4; ++k) {
      int rr = r + dr[k], cc = c + dc[k];
      if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
      if (val[rr][cc] != -1) continue;
      val[rr][cc] = val[r][c] + 1;
      que.emplace(rr, cc);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      ans += val[i][j];
  }
  printf("%lld\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
