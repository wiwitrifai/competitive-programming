#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N][N];

int rnk[N][N], tmp[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> id;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; ++j) {
      rnk[i][j] = s[i][j];
      id.emplace_back(i, j);
    }
  }
  int nm = n * m;
  for (int gap = 1; gap <= m; gap <<= 1) {
    auto get_val = [&](pair<int, int> pos) {
      int r = pos.first, c = pos.second;
      int c2 = (c + gap);
      if (c2 >= m) c2 -= m;
      return make_pair(rnk[r][c], rnk[r][c2]);
    };
    auto cmp = [&](pair<int, int> lef, pair<int, int> rig) {
      return get_val(lef) < get_val(rig);
    };
    sort(id.begin(), id.end(), cmp);
    int cur = 0;
    for (int i = 0; i < nm; ++i) {
      if (i > 0 && cmp(id[i-1], id[i]))
        ++cur;
      tmp[id[i].first][id[i].second] = cur;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        rnk[i][j] = tmp[i][j];
      }
    }
  }
  for (int gap = 1; gap <= n; gap <<= 1) {
    auto get_val = [&](pair<int, int> pos) {
      int r = pos.first, c = pos.second;
      int r2 = (r + gap);
      if (r2 >= n) r2 -= n;
      return make_pair(rnk[r][c], rnk[r2][c]);
    };
    auto cmp = [&](pair<int, int> lef, pair<int, int> rig) {
      return get_val(lef) < get_val(rig);
    };
    sort(id.begin(), id.end(), cmp);
    int cur = 0;
    for (int i = 0; i < nm; ++i) {
      if (i > 0 && cmp(id[i-1], id[i]))
        ++cur;
      tmp[id[i].first][id[i].second] = cur;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        rnk[i][j] = tmp[i][j];
      }
    }
  }
  int r = -1, c = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (rnk[i][j] == 0)
        r = i, c = j;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = r + i, y = c + j;
      if (x >= n) x -= n;
      if (y >= m) y -= m;
      printf("%c", s[x][y]);
    }
    printf("\n");
  }
  return 0;
}
