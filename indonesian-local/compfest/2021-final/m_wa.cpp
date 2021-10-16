/**
 * Verdict: WA
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 2020;
const long long inf = 1e18;

long long dist[N][N];
char s[N][N];
pair<int, int> from[N][N];

vector<int> dx = {-1, -1, -1, 0,  1, 1, 1,  0};
vector<int> dy = {-1,  0,  1, 1, -1, 0, 1, -1};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  ++n, ++m;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  priority_queue<pair<long long, pair<int, int>>> pq;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '1') {
        dist[i][j] = 0;
        pq.emplace(make_pair(0, make_pair(i, j)));
        from[i][j] = {i, j};
      } else {
        dist[i][j] = inf;
      }
    }
  }
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    long long d = -top.first;
    auto pos = top.second;
    if (d != dist[pos.first][pos.second]) continue;
    auto orig = from[pos.first][pos.second];
    for (int i = 0; i < (int)dx.size(); ++i) {
      int x = pos.first + dx[i], y = pos.second + dy[i];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      long long zx = x - orig.first, zy = y - orig.second;
      long long dcur = zx * zx + zy * zy;
      if (dist[x][y] > dcur) {
        dist[x][y] = dcur;
        from[x][y] = orig;
        pq.emplace(make_pair(-dcur, make_pair(x, y)));
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += dist[i][j];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
