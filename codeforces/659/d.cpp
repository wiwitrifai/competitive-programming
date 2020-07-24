#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(n, vector<int>(m, 0));
  vector<int> row(n), col(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
      row[i] = max(row[i], a[i][j]);
      col[j] = max(col[j], a[i][j]);
    }
  }
  vector<pair<int, int>> pos;
  vector<bool> used(n * m + 1);
  sort(col.begin(), col.end());
  reverse(col.begin(), col.end());
  sort(row.begin(), row.end());
  reverse(row.begin(), row.end());
  for (int x : col)
    used[x] = true;
  for (int x : row)
    used[x] = true;
  int iter = n * m;
  auto nxt = [&]() {
    --iter;
    while (iter > 0 && used[iter]) --iter;
    assert(iter > 0);
    return iter;
  };
  int r = 0, c = 0;
  vector<vector<int>> ans(n, vector<int>(m, 0));
  while (r < n || c < m) {
    if (c == m || (r < n && row[r] > col[c])) {
      ans[r][c-1] = row[r];
      for (int j = c-2; j >= 0; --j)
        ans[r][j] = nxt();
      ++r;
    } else if (r == n || row[r] < col[c]) {
      ans[r-1][c] = col[c];
      for (int j = r-2; j >= 0; --j)
        ans[j][c] = nxt();
      ++c;
    } else {
      assert(r < n && c < m);
      assert(row[r] == col[c]);
      ans[r][c] = row[r];
      for (int j = c-1; j >= 0; --j)
        ans[r][j] = nxt();
      for (int j = r-1; j >= 0; --j)
        ans[j][c] = nxt();
      ++r;
      ++c;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      printf("%d%c", ans[i][j], j+1 == m ? '\n' : ' ');
  }
  return 0;
}
