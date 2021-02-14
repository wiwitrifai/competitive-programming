#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e9 + 7;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

char s[N][N];
int guard[N][N];
int dist[N][N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  priority_queue<pair<int, int>> pq;
  auto enc = [&](int r, int c) {
    return r * m + c;
  };
  for (int i = 0; i < k; ++i) {
    int r, c, d;
    scanf("%d %d %d", &r, &c, &d);
    --r, --c;
    ++d;
    if (guard[r][c] < d) {
      guard[r][c] = d;
      pq.emplace(d, r * m + c);
    }
  }
  while (!pq.empty()) {
    int d, pos;
    tie(d, pos) = pq.top();
    pq.pop();
    int r = pos / m, c = pos - r * m;
    if (guard[r][c] != d) continue;
    if (d <= 1) continue;
    for (int i = 0; i < 4; ++i) {
      int rr = r + dr[i], cc = c + dc[i];
      if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
      if (s[rr][cc] == '#') continue;
      if (guard[rr][cc] >= d-1) continue;
      guard[rr][cc] = d-1;
      pq.emplace(d-1, enc(rr, cc));
    }
  }
  int rfrom, cfrom, rto, cto;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'S') {
        rfrom = i;
        cfrom = j;
      } else if (s[i][j] == 'E') {
        rto = i;
        cto = j;
      }
      dist[i][j] = inf;
    }
  }
  if (guard[rfrom][cfrom] == 0) {
    dist[rfrom][cfrom] = 0;
    pq.emplace(0, enc(rfrom, cfrom));
  }
  while (!pq.empty()) {
    int d, pos;
    tie(d, pos) = pq.top();
    d = -d;
    pq.pop();
    int r = pos / m, c = pos - r * m;
    if (dist[r][c] != d) continue;
    for (int i = 0; i < 4; ++i) {
      int rr = r + dr[i], cc = c + dc[i];
      if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
      if (s[rr][cc] == '#') continue;
      if (guard[rr][cc] || dist[rr][cc] <= d+1) continue;
      dist[rr][cc] = d + 1;
      pq.emplace(-(d+1), enc(rr, cc));
    }
  }
  if (dist[rto][cto] >= inf) {
    puts("IMPOSSIBLE");
  } else {
    printf("%d\n", dist[rto][cto]);
  }
  return 0;
}
