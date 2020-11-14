#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((a[i][j] & 1) != ((i+j) & 1)) {
        ++a[i][j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d%c", a[i][j], j+1 == m ? '\n' : ' ');
    }
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
