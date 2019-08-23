#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int a[N][N], b[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", a[i]+j);
  bool ok = 1;
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
        ans.emplace_back(i, j);
        b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      ok &= a[i][j] == b[i][j];
    }
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
