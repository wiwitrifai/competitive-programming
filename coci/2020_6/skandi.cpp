#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char grid[N][N];
bool cek[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", grid[i]);
  vector<pair<int, int>> pos;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '1') {
        pos.emplace_back(i, j);
      }
    }
  }
  int nmask = 1 << (pos.size() * 2);
  int best = nmask - 1;
  for (int mask = 0; mask < nmask; ++mask) {
    if (__builtin_popcount(mask) >= __builtin_popcount(best)) {
      continue;
    }
    memset(cek, 0, sizeof cek);
    for (auto it : pos) {
      cek[it.first][it.second] = 1;
    }
    for (int i = 0; i < 2 * (int)pos.size(); ++i) {
      if (mask & (1 << i)) {
        int r = pos[i/2].first, c = pos[i/2].second;
        if (i & 1) {
          ++r;
          while (r < n) {
            if (grid[r][c] == '1') break;
            cek[r][c] = 1;
            ++r;
          }
        }
        else {
          ++c;
          while (c < m) {
            if (grid[r][c] == '1') break;
            cek[r][c] = 1;
            ++c;
          }
        }
      }
    }
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ok &= cek[i][j];
      }
    }
    if (ok) {
      best = mask;
    }
  }
  printf("%d\n", __builtin_popcount(best));
  for (int i = 0; i < 2 * (int)pos.size(); ++i) {
    if (best & (1 << i)) {
      int r = pos[i/2].first+1, c = pos[i/2].second+1;
      if (i & 1) {
        printf("%d %d DOLJE\n", r, c);
      }
      else {
        printf("%d %d DESNO\n", r, c);
      }
    }
  }
  return 0;
}
