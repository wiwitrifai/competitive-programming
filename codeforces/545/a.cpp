#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

vector<int> row[N], col[N];

int a[N][N], ans[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i]+j);
      row[i].push_back(a[i][j]);
      col[j].push_back(a[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    sort(row[i].begin(), row[i].end());
    row[i].erase(unique(row[i].begin(), row[i].end()), row[i].end());
  }
  for (int i = 0; i < m; ++i) {
    sort(col[i].begin(), col[i].end());
    col[i].erase(unique(col[i].begin(), col[i].end()), col[i].end());
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int r = lower_bound(row[i].begin(), row[i].end(), a[i][j]) - row[i].begin();
      int c = lower_bound(col[j].begin(), col[j].end(), a[i][j]) - col[j].begin();
      int res = max(r, c) + max((int)row[i].size() - r, (int)col[j].size() - c);
      printf("%d%c", res, j == m-1 ? '\n' : ' ');
    }
  }

  return 0;
}