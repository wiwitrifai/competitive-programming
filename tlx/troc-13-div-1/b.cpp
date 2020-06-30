#include <bits/stdc++.h>

using namespace std;

const int N = 303;

int p[N * N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

int cnt;

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  --cnt;
  p[u] = v;
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(n, vector<int>(m, 0));
  vector<pair<int, int>> all;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
      all.emplace_back(a[i][j], i * m + j);
    }
  }
  memset(p, -1, sizeof p);
  cnt = 0;
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  int ans = cnt;
  for (int i = 0; i < (int)all.size();) {
    int now = all[i].first;
    while (i < (int)all.size() && all[i].first == now) {
      int x = all[i].second / m, y = all[i].second % m;
      ++cnt;
      for (int j = 0; j < 4; ++j) {
        int xx = x + dx[j], yy = y + dy[j];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (a[xx][yy] < now) continue;
        merge(all[i].second, xx * m + yy);
      }
      ++i;
    }
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
